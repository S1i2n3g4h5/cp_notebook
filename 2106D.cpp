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



const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
 
    ll n,k;cin>>n>>k;
    vector<ll>a(n),b(k);
    f(i,0,n)cin>>a[i];
    f(i,0,k)cin>>b[i];



    sort(a.begin(), a.end());
    sort(b.begin(), b.end());



    


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