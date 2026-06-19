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
    directly connected 

    try both dfs + bfs

  */

    ll n,m;cin>>n>>m;
    vll arr(n+1);
    f(i,1,n+1)cin>>arr[i];
    vector<vll>adj(n+1);
    f(i,0,n-1){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    ll ans=0;


    //#############################################
    // DFS
    //#############################################
    auto dfs = [&](auto&&dfs, ll u, ll parent, ll consecutive_cats){
        if(arr[u] == 1){
            consecutive_cats++;
        }
        else{
            consecutive_cats = 0;
        }

        if(consecutive_cats > m)
            return;

        bool is_leaf = true;
        for(auto v:adj[u]){
            if(v != parent){
                is_leaf = false;

                dfs(dfs,v,u,consecutive_cats);
            }
        }

        if(is_leaf){
            ans++;
        }

    };
    
    dfs(dfs, 1,0,0);
    cout << ans << "\n";

}

/*
void dfs(int u, int p, int consecutive_cats) {
    // 1. State Transition
    if (has_cat[u]) {
        consecutive_cats++;
    } else {
        consecutive_cats = 0;
    }

    // 2. Kill Switch
    if (consecutive_cats > m) return;

    // 3. Leaf Check & Expansion
    bool is_leaf = true;
    for (int v : adj[u]) {
        if (v != p) { // Don't walk backwards
            is_leaf = false;
            dfs(v, u, consecutive_cats);
        }
    }

    // A leaf is a node with no children to expand to. 
    // Root is not a leaf unless N=1 (but constraints say N >= 2).
    if (is_leaf) {
        valid_leaves_dfs++;
    }
}
*/
int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}