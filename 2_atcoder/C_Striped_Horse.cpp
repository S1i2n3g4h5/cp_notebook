#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = 1;


void solve(){
  
    int n,x;cin>>n>>x;
    vector<ll>arr(2*x,0);
    f(i,0,n){
        ll c;cin>>c;
        arr[i%(2*x)] += c; 
    }

    ll cur=0LL;
    f(i,0,x)cur+=arr[i];

    ll ans = cur;
    f(i,x,2*x+x){
        cur += arr[i%(2*x)];
        cur -= arr[(i-x) %(2*x)];
        ans = min(ans, cur);
    }

    print(ans);
  
  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   