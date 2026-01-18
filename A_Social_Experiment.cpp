#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 2) {
        cout << 2 << endl;
    } else if (n == 3) {
        cout << 3 << endl;
    } else {
        // For any n >= 4, we can balance groups to get 0 or 1
        // If n is even, we can always reach a 0 difference (e.g., 4=2+2, 6=3+3)
        // If n is odd, we can always reach a 1 difference (e.g., 5=2+3, 7=2+2+3)
        cout << (n % 2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}