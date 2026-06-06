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


const bool multipleTestCases = 1; 

void solve(){
  /*

    since its XOR, we know that,
        bits do not interact wiht other bits.

    since due to large constraint, there must be some o(1) mathematical formula
    
    so, if entire array consisting of single bits only o,1
    then, the answer can be solved, imilarly, for k-bit its (singlebitanswer)^k

    and lets say... 
        a,b,c,d,e  some array
then applyng fcuntion once - (k=0, 2^k=1)
    a^b^c

then applying funciotn twice - (k=1, 2^1=2);
    left - a^b^c
    center - b^c^d
    right - c^d^e
    now together xor- left^center^right
    final -> a^c^e

    also total 4 options fr each bit -> {00,11,01,10}

  */

    ll n,k;cin>>n>>k;

    ll mod = 998244353;

    ll L = (1ll<<k)%n;

    // determining total number of indedpended cycles
    ll g = __gcd(n,L);
    ll ways_per_bit = 1;
    
    // total lenght of single independent cycel
    ll m = n/g;

    if(m%3 ==0){
        // 4 combiations work per independed cycle path
        ways_per_bit = fast_power(4,g,mod);
    }
    else{
        // only the all-zero combination works
        ways_per_bit = 1;
    }


    print(fast_power(ways_per_bit, k,mod));

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
