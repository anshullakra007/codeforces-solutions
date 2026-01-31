#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i=0;i<n;i++){cin>>v[i];}

    vector<int>c=v;
    sort(c.begin(),c.end());
    bool possible=true;
    for (int i =0;i<n;i++){
        if(c[i]%2 != v[i]%2){
            possible =false;
            break;
        }
    }
    if(possible){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}