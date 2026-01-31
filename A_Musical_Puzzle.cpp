#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s ;
    cin >> n>>s;
    // vector<int> v(n);
    set <string> st;
    for(int i =0;i<n-1;i++){
        string sub=s.substr(i,2);
        st.insert(sub);

    }
    cout<<st.size()<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}