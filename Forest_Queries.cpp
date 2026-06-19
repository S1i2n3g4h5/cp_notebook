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
    2d prefix

  */

  ll n,m;cin>>n>>m;
  vector<string>arr(n);
  f(i,0,n){
    cin>>arr[i];
  }

  vector<vll>pf(n+1,vll(n+1,0));
  f(i,1,n+1){
    f(j,1,n+1){

      pf[i][j] = (arr[i-1][j-1] == '*'?1:0) + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];

    }
  }

  while(m--){
    ll x1,y1,x2,y2;cin>>y1>>x1>>y2>>x2;

    ll res = pf[y2][x2] - pf[y1-1][x2] - pf[y2][x1-1] + pf[y1-1][x1-1];

    cout << res << "\n";

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