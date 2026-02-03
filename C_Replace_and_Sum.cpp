#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    // 1. Read Input
    // We use size n+1 to align with 1-based queries (l, r)
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> b[i];

    // 2. Step 1: Create the "Best Option" Array (C)
    // C[i] is just the larger of a[i] or b[i]
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) {
        c[i] = max(a[i], b[i]);
    }

    // 3. Step 2: Create "Future Max" Array (SufMax)
    // We fill this BACKWARDS.
    vector<int> sufMax(n + 1);
    
    // The last element is just itself (no one to the right)
    sufMax[n] = c[n];

    // Loop from second-to-last down to 1
    for(int i = n - 1; i >= 1; i--) {
        // Current spot gets max of: ITSELF vs. The Best of the Right Side
        sufMax[i] = max(c[i], sufMax[i+1]);
    }

    // 4. Step 3: Prefix Sums for Fast Queries
    // Use long long because sums can get large!
    vector<long long> pref(n + 1);
    pref[0] = 0; // Base case

    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + sufMax[i];
    }

    // 5. Answer Queries
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        // Sum of range [l, r] is Pref[r] - Pref[l-1]
        cout << pref[r] - pref[l-1] << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}