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


const bool multipleTestCases = 1; 
void solve(){
  /*
    crossing meaning = i<j and ai>=aj

    So we wll be usiing ordered set
    to query how many lements currently in set are stricly less tahn arr[j];
    using -1,ensure we dont count any lements euq to arr[j] as less than.

    then, we find the lements greater than or equal to arr[j] is the complement

    then just nsert ehe and continue the intersection


  */
    
    ll n;cin>>n;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }
    
    ordered_multiset osd;
    ll ans=0;

    f(j,0,n){


        ll elemnts_less = osd.order_of_key({arr[j],-1});

        ans += j - elemnts_less;

        osd.insert({arr[j], j});

    }

    cout << ans<<"\n";

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