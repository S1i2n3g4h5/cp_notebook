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

    odd case: postions fixed already
    even case: need to check prefix + sufix costs for best cost possible


  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    auto cost = [&](int i){
        ll max_neighbour = max(arr[i-1], arr[i+1]);
        if(arr[i] > max_neighbour)
            return 0ll;
        return max_neighbour - arr[i] + 1;
    };


    if(n&1){
        ll totcost=0;
        for(int i=1;i<n-1;i+=2)
            totcost += cost(i);

        print(totcost);
        return;
    }


    vll pf(n,0),suf(n,0);
    for(int i=1;i<n-1;i+=2){
        pf[i] = cost(i);
        if(i>1)
            pf[i] += pf[i-2];
    }

    for(int i=n-2;i>=2;i-=2){
        suf[i] = cost(i);
        if(i<n-2)
            suf[i] += suf[i+2];
    }

    
    ll ans = pf[n-3];

    for(int i=1;i<n-3;i+=2){
        ll current_cost = pf[i] + suf[i+3];

        ans = min(ans, current_cost);
    }

    ans = min(ans, suf[2]);

    print(ans);

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