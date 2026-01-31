#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int min=INT_MAX;
    int oddcnt=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]<min){
            min=v[i];

        }
        if(v[i]%2!=0){
            oddcnt++;
        }

    }
    if(oddcnt==0){
        cout<<"YES\n";
        return;

    }
    if(min&2!=0){
        cout<<"YES\n";
        return;

    }
    cout<<"NO\n";

    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}