#include <bits/stdc++.h>
using namespace std;

void solve() {
    // int n;
    // cin >> n;
    // vector<int> v(n);
    string s;
    cin>>s;
    int days=0;
    set<char> mem;
    for(char c:s){
        mem.insert(c);
        if(mem.size()>3){
            days++;
            mem.clear();
            mem.insert(c);


        }
        
        

    }
    if(!mem.empty()){
            days++;
        }
    cout<<days<<endl;
    
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}