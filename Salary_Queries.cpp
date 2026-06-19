/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<long long,long long>, null_type, less<pair<long long,long long>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
//For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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


const bool multipleTestCases = 0; 
void solve(){
  /*

  */

    ll n,q;cin>>n>>q;
    vll arr(n+1,0);
    ordered_multiset ost;    
    f(i,1,n+1){
        cin>>arr[i];
        ost.insert({arr[i], i});
    }


    while(q--){
        char t;cin>>t;
        
        if(t == '!'){
            // Update
            ll k,x;cin>>k>>x;

            // erase
            ost.erase({arr[k], k});

            // update
            arr[k] = x;

            // insert
            ost.insert({arr[k], k});

        }
        else{
            // Query
            ll a,b;cin>>a>>b;

            /*
                order_of_key(X) - returns number of elems strictly smaller than X
            */

            ll cntb = ost.order_of_key({b, 2e9});
            ll cnta = ost.order_of_key({a,0});

            cout << cntb - cnta << "\n";
        }
    }


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