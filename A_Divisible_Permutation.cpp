#include <bits/stdc++.h> // The \"God Header\" - includes ALL STL tools
using namespace std;

void solve() {
    // 1. Read Input
    int n;
    cin >> n;

    
    // Example: Using a Vector
    vector<int> v(n+1);
    // for(int i = 0; i < n; i++) cin >> v[i];
    int small=1;
    int big =n;
    bool flip =true;
    for(int i=n;i>=1;i--){
        if(flip){v[i]=small;
        small++;}
        else{v[i]=big;
        big--;}

        flip=!flip;


    }    
    for (int i=1;i<=n;i++){
        cout<<v[i]<<" ";


    }
    cout<<endl;

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