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

void solve(){
  /*

    SO Lets learn Post-Order Tree DP :)
    _____________________________________

    So this is more like STANDARD DFS technique

    So the child node must report to its parent whether its has successfully elected a city in its subtree?
    return 0=subtree empty
           1=city down in branch elected. this coves any broken roads.


    ---

    since we need to select the corrputed city
    we select form bottom the very first that comes
    then its easy for us to grow from that and find the candidates

  */

    ll n;cin>>n;
    vector<vector<pll>>adj(n+1, vector<pll>());
    vll ans;
    f(i,0,n-1){
        ll u,v,t;cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }


    auto dfs = [&](auto&& dfs, ll u, ll p, ll type_to_parent) -> ll {
        ll subtree_candidate = 0;

        for(auto& edge:adj[u]){
            ll v = edge.first;
            ll edge_type = edge.second;

            // crucial -> do not walk backward to the parent
            if(v != p){
                ll child_signal = dfs(dfs, v,u,edge_type);

                subtree_candidate += child_signal;

            }
        }


        // Post-order decision - back from child traversal
        // if road to parent is broekn and no child below us fixed it(sum = 0)
        if(type_to_parent == 2 and subtree_candidate == 0){
            ans.push_back(u);
            
            // sending 1 up to our parent. This branch is secure
            return 1;
        }

        // upward-phase -> if we picked city, or child did, send 1
        return (subtree_candidate > 0 ? 1ll : 0ll);

    };


    dfs(dfs,1,0,1);

    cout << ans.size() << "\n";
    for(auto x:ans){
        cout << x << " ";
    }
    cout <<"\n";

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