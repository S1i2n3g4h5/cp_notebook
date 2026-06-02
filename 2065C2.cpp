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

    basic lowebound and checking condition only

  */

    ll n,m;cin>>n>>m;
    vll a(n),b(m);
    f(i,0,n)cin>>a[i];
    f(i,0,m)cin>>b[i];


    sort(all(b));

    ll prevval = -2e18;

    f(i,0,n){
        ll op1 = 2e18, op2=2e18;


        // option1 - keep same elemnt 
        if(a[i] >= prevval){
            op1 = a[i];
        }

        // option2
        /*
            since newleemtn value >= prevval
            bj - a[i] >= preval
            bj >= prevvval + a[i];
            
        */
        auto it = lower_bound(all(b), prevval + a[i]);

        if(it != b.end()){
            op2 = *it - a[i];
        }

        
        ll bestcurr = min(op1, op2);

        if(bestcurr == 2e18){
            print("NO");
            return;
        }

        prevval = bestcurr;
    }


    print("YES");
    
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