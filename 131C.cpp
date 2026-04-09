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
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 


void solve(){
  /*
    direct ncr on boys*girls * (t-1) wont work cuz given question said, `the variants that only differ in the composition of the troupe are considered different`

    Hence to get that final values must be getting summed up to find tot different pairs as of boys selected [4,t-1]
    with lefout girls as t-b

  */

    int n,m,t;cin>>n>>m>>t;

    auto nCr = [](auto n, auto r){
        if (r<0  or  r>n) 
            return 0ll;

        r = min(r, n-r);

        ll res = 1;
        f(i,1,r+1){
            res = res * (n - r + i)/i;
        }
        return res;
    };


    // print(nCr(n,4)*nCr(m,1)*(t-4));


    ll ans =0;
    f(b,4,t){
        int curr_boys = b;
        int curr_girls = t - b;

        ans += (nCr(n, curr_boys) * nCr(m,curr_girls));
    }

    print(ans);

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