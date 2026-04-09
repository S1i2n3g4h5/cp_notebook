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

    for finding the best x which should be large as possibl
    cuz it will help quickly make the elements equal with fewest operations

    (M - ai)/x   here to reach the target M from value ai

    the common x can be asily find using the gcd property,
    and finding the diff which results into working optimal solution



  */

    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];


    if(n==1){
        print(1);
        return;
    }


    sort(all(a));


    ll m = a[n-1];
    ll x = 0;
    f(i,0,n-1){
        x = __gcd(x, m - a[i]);
    }


    // ops for existing elem
    ll ops=0;
    f(i,0,n){
        ops += (m - a[i]) / x;
    }


    // appending n+1th elem
    ll k=1;
    for(int i=n-2;i>=0;i--){
        // skip if someone already in some spot
        if(a[i] == m-k*x){
            k++;
        }
        else{
            break;
        }
    }

    ops += k;

    print(ops);

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