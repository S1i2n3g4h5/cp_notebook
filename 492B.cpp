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
    need to find the least overlapping points such that the diff is atleast >=1
    binary search :()


  */

    ll n,l_max;cin>>n>>l_max;
    vector<double>arr(n);
    f(i,0,n)cin>>arr[i];

    sort(all(arr));
    
    double mxdist = 0.0;
    f(i,1,n) mxdist = max(mxdist, abs(arr[i-1]-arr[i]));


    double ans=mxdist/2;
    f(i,0,n){
        ans = max(mxdist/2, max(arr[0] - 0, l_max - arr[n-1]));
    }
    
    cout << fixed << setprecision(10);
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