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

    since normal implementaiotn cna give tle;
    we will use queue to store immediate leafs to be deleted properly
    hence this is really good problem to build intuition around queue
    
  */

    // string empty;cin>>empty;
    ll n,k;cin>>n>>k;
    vector<vll>adj(n+1);
    vll degree(n+1,0);
    f(i,0,n-1){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    
    // EDGE case
    if(n == 1){
        if(k == 0)
            cout << "1\n";
        else
            cout << "0\n";
        return;
    }


    // TO track whihci step a node was delted to stay withign <= k steps
    vll layer(n+1,0);

    queue<ll>q;
    f(i,1,n+1){
        if(degree[i] == 1){
            q.push(i);
            layer[i] = 1;
        }
    }

    ll remaining_nodes = n;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        if(layer[u] > k)
            break;


        remaining_nodes--;

        for(ll v:adj[u]){
            if(degree[v] >= 1){
                degree[v]--;

                if(degree[v] == 1){
                    q.push(v);
                    layer[v] = layer[u] + 1;
                }
            }
        }
    }

    cout << remaining_nodes << "\n";

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
