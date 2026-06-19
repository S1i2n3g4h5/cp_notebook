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
    instead of short-sighted approach which fials to account for better greedy rward

    we just se soethign like summing the packages from left and to rihgt
    and at any instead matching which matches good...

    and if none matched then its NO

  */

    ll n,k;cin>>n>>k;k--;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    ll left = k-1, right = k+1, sum1=0,sum2=0;
    ll health = arr[k];
    while(true){
        if(left < 0 or right >= n){
            break;
        }


        ll pos1 = left;
        ll pos2 = right;

        if(left>=0 and health + sum1 + arr[left] >= 0){
            sum1 += arr[left];
            left--;
        }

        if(right < n and health + sum2 + arr[right] >= 0){
            sum2 += arr[right];
            right++;
        }


        // check for stillness?
        if(pos1 == left and pos2 == right){
            break;
        }


        if(sum1 >=0 ){
            health += sum1;
            sum1 = 0;
        }

        if(sum2 >= 0){
            health += sum2;
            sum2 = 0;
        }

    }


    if(left < 0 or right >= n){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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