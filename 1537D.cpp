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

bool is_pow_2(ll n){
    return (n&(n-1)) == 0;
}

void solve(){
  /*
    since n=1 or prime is direct losing numbers
    
    we can divide n into 3 categories
    n is odd,even,even n power of 2

    n=odd  -> ince odd then all divisor also odd, hence odd-odd = even
  
    n= even +power of 2 -> cuz they reduce largest divisor hence for 2^k -> 2^k-1 -> 2^2k-3 ... 2^1
        means if k=even then alice win else bob
  
    n=even -> here it depends cuz we can also subtract odd divisor to get odd number which follow same process for odd
        but need to mke sure that the final unmber after diff is not evene again cuz that gives the competitor edge again

    
    odd -> bob
    even   alice
    even+2^k(even)    alice
    even+2^k(odd)     bob
  */

    ll n;cin>>n;


    if(n & 1){
        print("Bob");
    }
    else if(n%2 == 0 and !is_pow_2(n)){
        print("Alice");
    }
    else{
        int k = 63 - __builtin_clzll(n);
        if(k%2==0) print("Alice");
        else print("Bob");
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