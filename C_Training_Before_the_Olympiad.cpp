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

    even + even or odd+odd  -> giving max posible sum and this is what masha choose 1st priority
    masha tries to chooe the maximum possible ones of these ai,aj of sam parity and also of maximum

    and if sometig masha choose like odd+even or even+odd... -> this gets converted to evne evntually..
    and appnede elemnt is just-> (ai+aj-1)



    hence the ouput is just kind of running sum continuous average..

    in which we just need to have a control over how many odds,evens...


    ----

    on close inspection of testcase 4, we find 
    there is contnuousl penalty aswell rather than just -1

    as it repeast over a group of 3 odd cnts...
    hence -> penalty ->   oddncnt/3 + (oodcnt%3==0?1:0)


  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    if(n==1){
        cout << arr[0] << "\n";
        return;
    }


    ll oddcnt=0;
    ll currsum =0;
    f(i,0,n){
        currsum += arr[i];

        if(arr[i] & 1){
            oddcnt++;
        }


        cout << (i==0 ? arr[0] : currsum - (oddcnt/3 + (oddcnt%3 == 1)) ) << " \n"[i+1==n];
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