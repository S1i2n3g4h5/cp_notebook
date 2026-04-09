/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 1; 


void solve(){
  /*
    
  */
 
    ll x,y,n;cin>>x>>y>>n;
    
    // ll tmp=max(0ll,x * ((n+x-1) / x));  //ceil
    ll tmp = (n/x) * x;
    tmp += y;
    
    if(tmp > n)
        tmp -= x;
    
    print(tmp);
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