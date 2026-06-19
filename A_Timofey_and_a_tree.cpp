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

    
  */

    ll n;cin>>n;
    vector<pll>edges(n-1);
    f(i,0,n-1){
        cin>>edges[i].first>>edges[i].second;
    }
    vll color(n+1);
    f(i,1,1+n)cin>>color[i];

    
    // Finding the first bad edge
    ll root_u = -1, root_v = -1;
    for(auto edge:edges){
        if(color[edge.first] != color[edge.second]){
            root_u = edge.first;
            root_v = edge.second;

            break;            
        }
    }
    

    // Already colored..
    if(root_u == -1){
        cout << "YES\n1\n";
        return;
    }

 
    auto check_candidate = [&](ll vertex) -> bool{
        for(auto edge:edges){
            ll u = edge.first;
            ll v = edge.second;

            if(color[u] != color[v]){
                if(u != vertex and v != vertex){
                    return false;
                }
            }
        }
        return true;
    };


    if(check_candidate(root_u)){
        cout << "YES\n" << root_u << "\n";
        return;
    }
    else if(check_candidate(root_v)){
        cout << "YES\n" <<  root_v << "\n";
        return;
    }
    
    
    cout << "NO\n";
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