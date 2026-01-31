#include <bits/stdc++.h> // The \"God Header\" - includes ALL STL tools
using namespace std;

void solve() {
    // 1. Read Input
    int n;
    cin >> n;
    
    // // Example: Using a Vector
    // vector<int> v(n);
    // for(int i = 0; i < n; i++) cin >> v[i];
    
    // // Example: Using a Map to count frequencies
    // map<int, int> counts;
    // for(int x : v) {
    //     counts[x]++;
    // }
    
    // // Example: Using a Set to find unique elements
    // set<int> unique_elements;
    // for(int x : v) unique_elements.insert(x);
    
    // cout << unique_elements.size() << "\n";
    string s ;
    cin>>s;
    int total=0;
    int streak=0;
    bool generator=false;

    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            total++;
            streak++;


        }else{streak=0;}
        if(streak==3){generator=true;}

    }if(generator==true){
        cout<<2<<endl;
    }else{cout<<total<<endl;}
    
    
}

int main() {
    ios::sync_with_stdio(false); // Makes cin/cout fast
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}