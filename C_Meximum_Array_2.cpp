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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

// Boost Multiprecision (rare but lifesaving)
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// int128_t  : when ll overflows (products > 1e18)
// int256_t/int512_t/int1024_t : fixed ultra-large integers
// cpp_int : arbitrary precision integer, ideal for n! , Catalan numbers, huge DP counts


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


const bool multipleTestCases = 1; 
void solve(){
  /*

  since for each arr[i] we need to determine if it belongs to min or mex
  or none or both
  if belong to min, then =k put
  if belong to mex then put <k or .>k depending

  if(none then pput anythin)
  if both then cant both == k and >=k hence putting k+1 satisfy


  for implementaion, lets eep a boolena array to track what elemnt to put and cconition to satisfy


  */

  ll n,k,q;cin>>n>>k>>q;

  vll arr(n+1,0);
  vll mn(n+1,0),mx(n+1,0);
  while(q--){
    ll c,l,r;cin>>c>>l>>r;

    for(ll i=l;i<=r;i++){
      if(c==1){
        mn[i] = 1;
      }
      else{
        mx[i] = 1;
      }
    }
  }


  f(i,1,n+1){
    if(mx[i] == 1 and mn[i]==1){
      arr[i] = k+1;
    }
    else if(mx[i] == 1){
      arr[i] = i%k;
    }
    else{
      arr[i] = k;
    }
  }



  f(i,1,n+1)
    cout << arr[i] << " \n"[i==n];

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