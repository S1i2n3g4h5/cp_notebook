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


ll func(int i, bool intrade, int n, vll&prices, ll k, vector<vll>&memo){
    if(i>= n or k<=0){
        return 0ll;
    }

    if(memo[i][k] != -1){
        return memo[i][k];
    }


    ll buy=0;
    if(!intrade){
        buy = -prices[i] + func(i+1, true, n, prices, k, memo);
    }
    else{
        buy = prices[i] + func(i+1, false, n, prices, k-1, memo);
    }


    ll skip = func(i+1, intrade, n, prices, k, memo);

    
    return memo[i][k] = max(buy,skip);
}

void solve(){
  /*
  
    dp[i][j] = using j transactios for day[i]

  */
    ll n,k;cin>>n>>k;
    vll prices(n);
    f(i,0,n)cin>>prices[i];


    vector<vll>memo(n+1, vll(k+1,-1));

    
    func(0, false, n, prices, k, memo);
    
    print(memo[0][k] >= 1e9 ? -1 : memo[0][k]);
    
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