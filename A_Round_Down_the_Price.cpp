#include <bits/stdc++.h>
using namespace std;

void solve() {
    // int n;
    // cin >> n;
    // // vector<int> v(n);
    // string m;
    // cin>>m;
    long long m;
    cin>>m;
    long long p=1;
    while(p*10<=m){
        p*=10;

    }
    cout<<m-p<<endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}