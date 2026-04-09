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

void solve(){
  /*
    this does seems like normal greedy 
    and constraints boost confidence into greedy
    but its actually a dp proble :(
    
    
    but stil lthis was good problme for racticing the dp states logics
    like 1bit advanced from knapsack-styled backtracking

    dp[i][0] = rest
    dp[i][1] = contest  -> {1,3}
    dp[i][2] = gym  -> {2,3}

    also make sure to keep the conditino in check that
    no consecutive days to doing same activity :!

    and we just calculating the max score which we can subtrct from n which gives us our answer for min rest days;

    - doing +1 for contest, gym cuz we did some actvity this day

  */

    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];

    vector<vector<int>> dp(n+1, vector<int>(3,0));
    f(i,1,n+1){
        ll x = a[i-1];
        
        // Rest
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        // Contest
        if(x == 1 or x == 3){
            dp[i][1] = max({dp[i-1][0], dp[i-1][2]}) + 1;
        }

        // Gym
        if(x == 2 or x == 3){
            dp[i][2] =   max({dp[i-1][0], dp[i-1][1]}) + 1;
        }
    }

    ll mx = max({dp[n][0], dp[n][1], dp[n][2]});

    print(n - mx);

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