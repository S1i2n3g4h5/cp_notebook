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
    since gcd property is that it will either decrease or remain same as we take its prefix gcd

    and its only logarithmic changes done, cuz log2(1e5) ~ 17
    hence only 17 times atmax gcd wil change into our array.

    So on each step we are trying not to group similar powers of primes toegether..

    Henceif we look at it, we find that,we just need to greedy serach over
    log2(n) times cuz thats only how muhc gcd can change
    and another conditino like inside this selctioon process, if we reach the currentgcd == totalinitalgcd
    then it means we cant decrease further hence break the selection loop


    since the WhileLoop will run atmost 17 times cuz log2(1e5) (max limit of arr[i]) is just 17
    hence there is no overload

    TimeComplexity - o(17*1e5) -> 1.7x1e6 steps

  */

    ll n;cin>>n;
    vll arr(n);
    ll initial_gcd=0;
    f(i,0,n){
        cin>>arr[i];
        initial_gcd = __gcd(arr[i], initial_gcd);
    }

    sort(all(arr));


    ll total_sum =0;
    ll curr_gcd = arr[0];
    total_sum += curr_gcd;

    vector<bool>used(n,false);
    used[0] = 1;

    ll elems_picked = 1;

    while(elems_picked < n){
        if(curr_gcd == initial_gcd){
            break;
        }

        ll best_gcd = curr_gcd;
        ll best_idx = -1;

        f(i,0,n){
            if(!used[i] and __gcd(arr[i], curr_gcd) < best_gcd){
                best_gcd = __gcd(arr[i], curr_gcd);
                best_idx = i;
            }
        }

        if(best_gcd < curr_gcd){
            used[best_idx] = 1;
            curr_gcd = best_gcd;
        }
        else{
            // no elemnt can reduce further
            break;
        }

        total_sum += curr_gcd;
        elems_picked++;
    }
    
    f(i,elems_picked,n){
        curr_gcd = __gcd(curr_gcd, arr[i]);
        total_sum += curr_gcd;
    }

    cout << total_sum << "\n";

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