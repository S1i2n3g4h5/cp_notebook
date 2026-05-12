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

ll memo[10000005];


ll func(int idx, int start, vll&arr){
  if(idx < start)
    return 0;
  else if(idx == start) {
    return arr[start];
  }

  if(memo[idx]!=-1){
    return memo[idx];
  }

  ll pick = arr[idx] + func(idx-2, start,arr);

  ll notpick = func(idx-1, start,arr);

  return memo[idx] = max(pick, notpick);


}


void solve(){
  /*
    2 cases -
      1. rob from 1 to n-1 houses
      2. rob from 2 to n houses

  */

  ll n;cin>>n;
  vll arr(n);
  f(i,0,n)cin>>arr[i];


  if(n==1){
    print(arr[0]);
    return;
  }

  memset(memo, -1, sizeof(memo));
  ll ans1 = func(n-2, 0,arr);

  memset(memo, -1, sizeof(memo));
  ll ans2 = func(n-1, 1,arr);
  

  print(max(ans1, ans2));

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