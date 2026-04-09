/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    ((cout << args << " "), ...); cout << "\n";
}
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 1; 


void solve(){
  /*
    for maximizing the min sums from all arrays, we can try moving all mins to some common array then its ezy
  
    now instead of brute forcing implementation, we cna just store the 2 mins from each array and 
    formulaize the equation to get answer
  */

    int n;cin>>n;
    vector<vll> arr(n);


    ll mn_first=LLONG_MAX, mn_second=LLONG_MAX;
    ll tot_mns =0ll;

    f(i,0,n){

        int m;cin>>m;
        vll a(m);
        f(j,0,m)cin>>a[j];
        
        sort(all(a));

        
        // main logic...
        tot_mns += a[1];
        mn_first = min(mn_first, a[0]);
        mn_second = min(mn_second, a[1]);

    }

    print(tot_mns - mn_second + mn_first);

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if (multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}
