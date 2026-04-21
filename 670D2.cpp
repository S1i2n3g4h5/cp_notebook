/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 

void solve(){
  /*
    without that magic poweder this is all just min(bi/ai) for all i
    but with magic poweder we need to use it effeectively to incresae the total cookies ot be baked

    if we make X cookies then x-1 cookie also possible,
    whcih means monotonic property ,binary search possible



  */

    ll n,k;cin>>n>>k;
    vll a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    auto check  = [&](ll x){

        ll power_req = 0;
        f(i,0,n){
            ll req = x * a[i];
            if(req > b[i]){
                power_req +=  (req - b[i]);
            }

            if(power_req > k)return false;
        }
        return power_req <= k;

    };


    ll low=0,high=2e9;

    while(low<=high){
        ll mid = low+(high-low)/2;

        if(check(mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }


    print(low-1);

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}