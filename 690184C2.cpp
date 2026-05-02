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

map<ll,ll>memo;


ll explore(ll n, ll d, map<ll,ll>& memo){
    if(n == 1){
        return 0ll;
    }
    if (n<1) return 2e18+5;

    if(memo.count(n)) return memo[n];

    ll ans = 2e18+5;


    if((n-1)%d == 0){
        ans = min(ans, (n-1ll)/d);
    }

    if(n%2 ==0){
        ll res = explore(n/2, d, memo);
        if(res != 2e18+5){
            ans = min(ans, res+1);
        }

        if(n-d >=1){
            ll res2 = explore(n-d, d, memo);
            if(res2 != 2e18+5){
                ans = min(ans, res2 + 1);
            }
        }
    }
    else{
        if((d%2 != 0) and n-d>=1){
            ll res = explore((n-d), d, memo);
            if(res != 2e18+5){
                ans = min(ans, res+1);
            }
        }

    }



    return memo[n] = ans;

}



void solve(){
  /*

  */

    ll n,d;cin>>n>>d;

    memo.clear();

    if(n%2 !=0 and d%2==0 and (n-1)%d != 0){
        print("NO");
        return;
    }

    
    ll ans = (explore(n,d, memo));

    if(ans >= 2e18+5)print("NO");
    else{
        print("YES", ans);
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