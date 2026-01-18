#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store query details
struct Query {
    int l, r, id;
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    
    vector<Query> queries(q);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }

    // Stores the final water amount for each plant
    vector<long long> final_water(n + 1, 0);

    // Iterate through bit levels j = 0, 1, 2... until 2^j > n
    // Max N is 2e5, so 2^18 is sufficient.
    for (int j = 0; j < 20; ++j) {
        long long cost_mult = 1LL << j;       // 2^j (the lowbit value)
        long long S = 1LL << (j + 1);         // Step size: 2^(j+1)
        
        // If the smallest lowbit value exceeds n, no x <= n can have this lowbit
        if (cost_mult > n) break;

        // Constants for the linear function: Value = A*k + B_dynamic
        // Value = (i - l + 1) * 2^j
        // With i = rem + k*S, this becomes:
        // Value = (rem + k*S - l + 1) * 2^j
        // Value = (S * 2^j) * k + (rem - l + 1) * 2^j
        long long A = S * cost_mult;
        long long C_base = cost_mult; // used to derive the constant part

        // We organize queries into buckets based on the remainder of the 
        // starting index for this specific bit level.
        // Valid indices i satisfy: i - l + 1 == odd * 2^j
        // => i == l - 1 + 2^j  (mod 2^(j+1))
        
        int limit = min((long long)n + 1, S);
        vector<vector<int>> buckets(limit);
        bool active_level = false;

        for(int i = 0; i < q; ++i) {
            long long l = queries[i].l;
            long long r = queries[i].r;
            
            // Calculate the first index i >= l that has the correct lowbit pattern
            long long i_first = l - 1 + cost_mult;
            
            if (i_first > r) continue;
            
            // The remainder class this query affects
            long long rem = i_first % S; 
            
            // Only process if the remainder is within bounds of plant array
            if (rem <= n) {
                // Optimization: limit bucket size to effectively used remainders
                if(rem < limit) {
                    buckets[rem].push_back(i);
                    active_level = true;
                }
            }
        }

        if (!active_level) continue;

        // Process each remainder class
        for (int rem = 0; rem < limit; ++rem) {
            if (buckets[rem].empty()) continue;

            // Calculate size of the compressed array for this remainder
            // index = rem + k * S
            // Max k such that rem + k*S <= n
            int max_k = (n - rem) / S;
            
            // Difference arrays for linear range updates: (Slope * k + Constant)
            // We use size + 2 to handle boundary conditions safely
            vector<long long> DS(max_k + 2, 0); // Difference for Slope
            vector<long long> DC(max_k + 2, 0); // Difference for Constant

            for (int q_idx : buckets[rem]) {
                long long l = queries[q_idx].l;
                long long r = queries[q_idx].r;
                
                // Recalculate i_first to find k_start
                long long i_first = l - 1 + cost_mult;
                
                // Map global index to compressed index k
                // i_first is guaranteed to be in the sequence rem, rem+S, ...
                long long k_start = (i_first - rem) / S;
                
                // Find last valid k within range [l, r]
                // rem + k*S <= r
                long long k_end = (r - rem) / S;

                if (k_start > k_end) continue;

                // We need to add Value(k) for k in [k_start, k_end]
                // Value(k) = A * (k - k_start) + (cost_mult * cost_mult)
                // Note: i_first corresponds to term 1 of the sequence for THIS query, 
                // so f(i_first - l + 1) = f(2^j) = 2^j * 2^j = 4^j.
                // Let's verify:
                // i = rem + k*S. 
                // Val = (rem + k*S - l + 1) * cost_mult
                // We know i_first = l - 1 + cost_mult
                // So l - 1 = i_first - cost_mult
                // Val = (rem + k*S - (i_first - cost_mult)) * cost_mult
                // Val = (rem + k*S - (rem + k_start*S) + cost_mult) * cost_mult
                // Val = (S(k - k_start) + cost_mult) * cost_mult
                // Val = (S*cost_mult) * (k - k_start) + (cost_mult*cost_mult)
                // Val = A * k - A * k_start + C_sq
                
                long long C_sq = cost_mult * cost_mult;
                long long val_const = C_sq - A * k_start;

                // Update Slope Difference Array
                DS[k_start] += A;
                if (k_end + 1 < DS.size()) DS[k_end + 1] -= A;

                // Update Constant Difference Array
                DC[k_start] += val_const;
                if (k_end + 1 < DC.size()) DC[k_end + 1] -= val_const;
            }

            // Prefix sum to compute final values and add to global array
            long long cur_A = 0;
            long long cur_B = 0;
            for (int k = 0; k <= max_k; ++k) {
                cur_A += DS[k];
                cur_B += DC[k];
                
                long long addition = cur_A * k + cur_B;
                long long plant_idx = rem + (long long)k * S;
                
                if (plant_idx > 0 && plant_idx <= n) {
                    final_water[plant_idx] += addition;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << final_water[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}