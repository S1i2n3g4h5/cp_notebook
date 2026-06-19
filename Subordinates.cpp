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

// Boost Multiprecision (rare but lifesaving)
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// int128_t  : when ll overflows (products > 1e18)
// int256_t/int512_t/int1024_t : fixed ultra-large integers
// cpp_int : arbitrary precision integer, ideal for n! , Catalan numbers, huge DP counts


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


ll dfs(int u,vector<vll>&adj,vll&cnt){
    ll count=0;

    for(auto v:adj[u]){
        // adding current v as a sbordinate count
        count += 1+ dfs(v, adj,cnt);

    }

    cnt[u] = count;

    return count;    

}

const bool multipleTestCases = 0; 
void solve(){
  /*
    just build the graph and loop over its total childs

    since due to high constraints... normal grpah dfs/bfs won't work
    so its best to use the overlapping being done,
    like stariting from bottom to tup.. from leafs to root to count how many the subordinates are..


  */
    ll n;cin>>n;
    vector<vll>adj(n+1);
    f(i,2,n+1){
        ll boss;cin>>boss;

        // Directed edge from boss to subordinate
        adj[boss].push_back(i);
        // adj[i].push_back(boss);
    }
    

    vll cnt(n+1,0);
    dfs(1,adj,cnt);


    f(i,1,n+1){
        cout << cnt[i] << " \n"[i==n];
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