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

struct Time{
    ll start,end;
};

void solve(){
  /*

    start at some x, finished at x+D

    the distance of both times must be atleast D, that we can say is the minimum
    distance between any overlapping segment...

    ----

    since the suspect incoming must have contributed +1 to the entire its start till end range..
    so we just need to compute the final values of arr[start,end-D]
    with contribution +1 when each entering or leaving...

    which leads to difference array technique;

    and the combiations can be just n*(n-1)/2;
    since the order doenst amttern...


  */

    ll n,d;cin>>n>>d;
    vector<Time>arr(n);
    f(i,0,n){
        cin>>arr[i].start>>arr[i].end;
    }

    vll diff(1e7,0);
    f(i,0,n){
        ll l = arr[i].start;
        ll r = arr[i].end - d;

        if(l <= r){
            diff[l]++;
            diff[r+1]--;
        }

    }


    ll ans=0;
    ll curr_suspect = 0;
    f(i,1,1e6+5){
        curr_suspect += diff[i];

        if(curr_suspect >= 2){
            // choosing 2 culprits form avialble pool of all candidates avialae at the location/mansino
            
            ans += (curr_suspect * (curr_suspect -1))/2;
        }

    }

    cout << ans << "\n";


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