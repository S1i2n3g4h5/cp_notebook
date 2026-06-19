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


const bool multipleTestCases = 0; 

struct Gem{
    ll value, color, id;
};

void solve(){
  /*

  */

    ll n,k,m;cin>>n>>k>>m;
    vector<vll> t(n+1);
    f(i,0,n){
        ll c,v;cin>>c>>v;
        t[c].pb(v);
    }
    
    vll top,tail;
    f(i,0,n+1){
        if(!t[i].empty()){
            sort(rall(t[i]));

            top.push_back(t[i][0]);
            f(j,1,t[i].size()){
                tail.pb(t[i][j]);
            }

        }
    }


    sort(rall(top));

    // extras...
    if((ll)top.size() > m){
        f(i,m,top.size()){
            tail.push_back(top[i]);
        }
    }


    sort(rall(tail));


    ll ans=0;
    ll limit = min((ll)top.size(), m);
    f(i,0,limit){
        ans += top[i];
    }


    limit = min((ll)tail.size(), k-m);
    f(i,0,limit){
        ans += tail[i];
    }


    cout << ans << "\n";

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