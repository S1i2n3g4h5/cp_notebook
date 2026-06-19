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
    finding through binary power of 2s only
    difference then the difference wil be guessable
    cuz we removing 1 bit at a time

    we will  be subtracting starting from powers of two2s...
    2^0..2^k

    and lets say on kth step, thenumber o bibts become equal to cnt(new) and befor eit was cnt then
    1. cnt - cntnew = 1  ==== then bit k was inlcued into n 
    2. cnt - cntnew != 1 ==== then number of bits doenst increase 
       and bit m such that 2^m > 2^k.... hence adding 2^m to answer cuz of bit trasnfer

      

  */

  ll original_cnt;cin>>original_cnt;


  ll currcnt = original_cnt;
  ll ans=0;

  ll last_bit_pos=0, bits_found=0;
  while(bits_found < original_cnt){
    cout << "- " << (1ll << last_bit_pos) << endl;
    ll newcnt;cin>>newcnt;

    ll diff = newcnt - currcnt;
    ll actual_bit_pos = last_bit_pos + diff + 1;


    // adding...
    ans |= (1ll << actual_bit_pos);


    // next bit...
    last_bit_pos = actual_bit_pos;
    currcnt = newcnt;

    bits_found++;

  }


  cout << "! " << ans << endl;

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