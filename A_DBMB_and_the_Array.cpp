#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    
    int initial = 0;
    vector<int> v(n);
for(int i=0; i<n; i++){
    cin >> v[i];
} 


int original = 0;
for(int i=0; i<n; i++){
    original+= v[i];
}
    
    
    if (s >= original && (s - original) % x == 0) {
        cout << "YES"<<endl ;
    } else {
        cout << "NO"<<endl ;
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}