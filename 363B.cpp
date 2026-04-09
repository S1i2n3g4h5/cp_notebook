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
 
    ll n,k;cin>>n>>k;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    ll currsm=0;
    f(i,0,k){
        currsm += arr[i];
    }
    
    int mnidx =1;
    ll mn_sm=currsm;
    f(i,k,n){
        currsm -= arr[i-k];
        currsm += arr[i];
        // print(currsm);

        if(currsm < mn_sm){
            mn_sm = currsm;
            mnidx = i-k+2;
        }
    }

    print(mnidx);
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