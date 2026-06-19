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

    the questions boils to simple condition only
    to imlement effictevly we just keep track of

    total childeren and its parent's bad child
    with this the implementain becomes very smooth

  */

    ll n;cin>>n;
    vll total_child(n+1,0),bad_child(n+1,0);
    vll c(n+1);
    ll root = -1;
    f(i,1,n+1){
      ll p;cin>>p>>c[i];
      if(p == -1)
        root = i;
      else{
        total_child[p]++;

        if(c[i] == 1){
          bad_child[p]++;
        }
      }
    }

    vll deleted;
    f(i,1,n+1){
      if(c[i] == 1 and bad_child[i] == total_child[i]){
        deleted.push_back(i);
      }
    }

    if(deleted.empty()){
      cout << "-1\n";
    }
    else{
      for(auto x:deleted){
        cout << x << " ";
      }
      cout <<"\n";
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