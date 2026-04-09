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


const bool multipleTestCases = 0; 

void solve(){
  /*

    x is nice if x//b = k*(x mod b)

    k = [1,a];


    now x = q*b + r    (general format)

    and given - q = k*r;

    so x = (k*r)*b + r = r*(k*b + 1)

    but making sure thatn r>0 and r<b


    final eq -   loop k=1 to a ( loop r=1 to b-1 (r*(kb +1)) )
                [loop k=1 to 1 ( kb + 1 )  ] * [loop r=1 to b-1 (r)];
                 
    since the 2nd summing term is just ap series, we write its formula directly
    and similary on breaking down the first term as well, it forms pure formla ap

    ans = ((b-1)*b/2 ) * (b*(a*(a+1)/2)/2 + a)

               |                |
           2nd term          1st term    
 
  */

    ll a,b;cin>>a>>b;

    ll MOD = 1e9+7;

    
    ll sm_b = (b*(b-1)/2)%MOD;
    ll sm_a = ((a*(a+1)/2)%MOD * b + a)%MOD;

    print((sm_a*sm_b)% MOD);

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