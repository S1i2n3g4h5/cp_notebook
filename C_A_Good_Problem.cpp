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
    to get lexigraphical smallest, we set ai=l to as many lemnts
    cuz l<=ai<=r;

    lets say can a bit coolunn have a bitise AND result of 1?
    if every elemnt has 1 at bit j then the followein happens-
        -> if number of 1s on bit j is odd, then AND=1,XOR=1  (valid)
        -> if number of 1s on bit j is even, then AND=1, XOR=0 (invalid)

    hence, if n is even the bitwise and sum of entier array must be zeor...

    for odd its easy.
    main working starst off for the even...
    hence we require the use of smalelst integrer that we can put off 
    when reqireing tos the condition properly,
    eaning smoe value, whihc >l and such that l&val ==0
    meaning we nee dot flip of bits where l has 1 to 0, and find he smallest way to
    carry 1 over ot higher bit posisiont andmake val > l..
        -> val = (l+1) | ~l


    since we need to outpu any valid value from the resulting array,
    we cna output anyhtign valid... a[k]

  */

    ll n,l,r,k;cin>>n>>l>>r>>k;


    if(n&1){
        // array = [l,l....l];
        cout << l << "\n";
    }
    else if(n==2){
        // ipossible case to match AND + XOR
        cout << "-1\n";
    }
    else{

        /*
            n>=4 and even then array->
            [l,l,l...l,val,val]
        */

        ll val = 0;
        ll highest_bit=-1;
        for(int i=60;i>=0;i--){
            if((l>>i) &1){
                highest_bit = i;
                break;
            }
        }
        val = (1ll << (highest_bit +1));


        if(val > r){
            cout << "-1\n";
            return;
        }
        

        /*
            since need to output kth value,
            lets check if ew need to outut 
            `l`   <--- if in valid range
            `val`   <--- if outside range and ast 2 lement...

            [l,l,l...l,val,val]

        */

        if(k <= n-2){
            cout << l << "\n";
        }
        else{
            cout << val << "\n";
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