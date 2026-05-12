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


const bool multipleTestCases = 0; 


ll memo[1002][1002];

ll func(int idx, ll remweight, ll n, vll&weight, vll&v){
    if(idx == n or remweight==0){
        
        return 0;
    }

    if(memo[idx][remweight] != -1){
        return memo[idx][remweight];
    
    }


    // ll skip = func(idx+2, remweight, n,weight,v);
    ll skip = func(idx+1, remweight, n,weight,v);

    
    ll take=0;
    if(weight[idx] <= remweight){
        take  = v[idx] + func(idx+1, remweight - weight[idx], n,weight,v);
    }
    
    return memo[idx][remweight] = max(skip, take);
}

void solve(){
  /*

  */

    ll n,w;cin>>n>>w;
    vll weight(n),v(n);

    f(i,0,n)cin>>weight[i];
    f(i,0,n)cin>>v[i];
    
    
    memset(memo, -1,sizeof(memo));


    print(func(0,w,n,weight,v));

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