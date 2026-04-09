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
#define debug(x) cout<<#x<<" = "<<x<<"\n"
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
  
  */
    ll n,l,r,ql,qr;cin>>n>>l>>r>>ql>>qr;
    vll a(n);
    f(i,0,n)cin>>a[i];


    vll prefix(n+1,0);
    f(i,0,n)
        prefix[i+1] = prefix[i] +a[i];


    ll ans=LONG_LONG_MAX;
    f(i,0,n+1){
        ll leftcost;
        ll rightcost;
        // if(i==0){
        //     leftcost = 0;
        //     rightcost = prefix[n];
        // }
        // else{
        leftcost = prefix[i] * l;
        rightcost = (prefix[n]-prefix[i]) * r;
        // }


        ll penalty;
        if(abs(n-i - i) <= 1){
            penalty =0;
        }
        else if(i > (n-i + 1)){
            penalty = (i - (n-i) - 1)*ql;
        }
        else{
            penalty = ((n-i) - i -1)*qr;
        }

        ans = min(ans, leftcost + rightcost  + penalty);

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
