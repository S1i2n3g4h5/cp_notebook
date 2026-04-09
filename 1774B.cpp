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
    specific color appearching only once every k cells

    this is very similar to the pigeonhole logic
    n/k full blocks of k sized colors.
    n%k  remaining last kth block

    maxfreq = ceil(n/k)  max times any color can appear

    1. no ai can be greater than ceil(n/k)  -> no
    2. total slots available for color with freqency n/k is exactly n%k

  */

    ll n,m,k;cin>>n>>m>>k;
    vll arr(m);
    ll mx=0;
    f(i,0,m){
        cin>>arr[i];
        mx = max(mx, arr[i]);
    }


    // 1.
    ll mxfreq = (n+k-1)/k;
    if(mx > mxfreq){
        print("NO");
        return;
    }

    // 2.
    ll cnt=0;
    f(i,0,m){
        if(arr[i] == mxfreq)
            cnt++;
    }

    //Only (n-1)%k + 1 colors can have the frequency (n+k-1)/k
    if(cnt > (n-1)%k +1){
        print("NO");
    }
    else{
        print("YES");
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