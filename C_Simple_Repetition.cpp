#include <bits/stdc++.h> // The \"God Header\" - includes ALL STL tools
using namespace std;

bool is_prime(int p){
    if(p<=1) return false;
    for(int i =2;i*i<=p;i++){
        if(p%i==0){
            
            return false;
        }
        
    }
    return true;
}

void solve() {
    // 1. Read Input
    long long  x,k;
    cin >>x>>k;

    if(k>1&&x>1){
        cout<<"NO"<<endl;
    }
    else{
        long long  y;
        if(k==1){
             y=x;


        }
        else{
            y=0;
            for(int i =0; i<k;i++){
                y=y*10+1;
            }
        }

    if(is_prime( y)){
        cout<<"YES"<<endl;

    }else{cout<<"NO"<<endl;}

    }
    
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