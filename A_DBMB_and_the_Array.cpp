#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    
    int current_sum = 0;
    
    // 1. Calculate Current Sum
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        current_sum += val;
    }
    
    // 2. Check if we strictly need to subtract (Impossible)
    if (current_sum > s) {
        cout << "NO\n";
        return;
    }
    
    // 3. Check if the gap is divisible by x
    int gap = s - current_sum;
    
    if (gap % x == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}