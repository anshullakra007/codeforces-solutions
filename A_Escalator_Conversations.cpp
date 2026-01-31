#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,k,H;
    cin >> n>>m>>k>>H;
    vector<int>h(n);
    for (int i=0;i<n;i++){
        cin>>h[i];

    }
    int count=0;
    for(int i =0;i<n;i++){
        int diff=abs(H-h[i]);
        if(diff==0)continue;
        bool division =(diff%k==0);
        bool steps=(diff/k<m);

        if( division &&  steps){
            count++;
        }
    

    }
    cout<<count<<endl ;
    
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}