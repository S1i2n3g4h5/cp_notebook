#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
 
    ll n;cin>>n;
    vector<string>arr(n);
    f(i,0,n)cin>>arr[i];


    int mx_size = 0;
    f(i,0,n){
        mx_size = max(mx_size, (int)arr[i].size());
    }
    

    f(i,0,n){
        // spaces to add
        int space_to_add = mx_size - (int)(arr[i].size()); 
        space_to_add = space_to_add / 2;
        cout << string( space_to_add,'.') << arr[i] << string(space_to_add,'.')<<"\n";
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}