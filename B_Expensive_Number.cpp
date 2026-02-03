#include <bits/stdc++.h> // The \"God Header\" - includes ALL STL tools
using namespace std;

void solve() {
    // 1. Read Input
    string  n;
    cin >> n;
    int zero=0;
    int max=1;
    for(int i=0;i<n.length();i++){
        if(n[i]=='0'){zero++;}
        else{
            int chain=zero+1;
            if(chain>max){
                max=chain;
            }
        }
        
        
    }
    cout<<n.length()-max<<endl;

    
    // Example: Using a Vector
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