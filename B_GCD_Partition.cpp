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
    since prefix gcd can only remain same or ecrease
    so we just need to form a prefix and continue a bigger gcd if not found
    and just split that only

    the optimla split can be found by checking from prefix and 
    suffix which k is optimla

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }


    ll total_sum = accumulate(all(arr), 0ll);
    ll max_gcd = 1;
    
    // ll curr_sum = 0;
    // f(i,0,n-1){
        //     curr_sum += arr[i];
        //     ll rem_sum = total_sum - curr_sum;
        
    //     ll tmpa = curr_sum;
    //     ll tmpb = rem_sum;

    //     while(tmpb){
    //         tmpa %= tmpb;
    //         swap(tmpa, tmpb);
    //     }

    //     max_gcd = max(max_gcd, tmpa);

    // }
    
    ll curr_sum = arr[0];
    f(i,1,n){
        ll remsum = total_sum - curr_sum;
        max_gcd = max(max_gcd, __gcd(remsum, curr_sum));
        curr_sum += arr[i];
    }

    cout << max_gcd<<"\n";

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