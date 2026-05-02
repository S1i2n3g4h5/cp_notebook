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


const bool multipleTestCases = 1; 

void solve(){
  /*
    since the column i t height h only be blocked from sliding right if only every cool to its right is atelast>=h height

    then claculaing the first occurance fo the a[i] which is causing big traffic jam to its left

    and then for destroying the 1 cube, we try destryong that which is the bottleneck
    and making sure we ont delete a[k] > smin[k]  cuz this wont result anything as its already sliding
    but instead we remove the one -> a[k] == smin[k];
  
  */

  int n;cin>>n;
  vll arr(n+1,0);
  f(i,1,n+1)cin>>arr[i];


  vll smin(n+2,2e9);
  for(int i=n;i>=1;i--){
    smin[i] = min(arr[i], smin[i+1]);
  }  


  // base oves
  ll base =0;
  f(i,1,n+1){
    base += (arr[i] - smin[i]);
  }


  // finding the bottlenecks
  vll focc(n+2,-1);
  f(i,1,n+1){
    if(smin[i] <= n and focc[smin[i]] == -1){
      focc[smin[i]] = i;
    }
  }


  ll max_gain=0;
  f(i,1,n+1){
    if(arr[i] == smin[i]){

      int l = focc[smin[i]];
      ll gain = i - l;

      max_gain = max(max_gain, gain);

    }
  }


  print(base + max_gain);

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