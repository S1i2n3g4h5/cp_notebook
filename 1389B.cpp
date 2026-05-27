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
    k -> max number of total moves
    z -> no more than z moves to left  (contraints range - [0, min(5,k)])

    for maximizing the back-n-forth for scoring maxxing, we need to find the adjacent
    pair giving max sum and we d backforth there only ofr leftover moves

    we can do normal looping fr this thing
    ad as for the z condtion, we can loop over cuz its samll and check which giving best answer
    
  */

    ll n,k,z;cin>>n>>k>>z;
    vll arr(n);
    ll mx=-1e5, mn=1e5;
    ll currmoves=0;
    f(i,0,n){
        cin>>arr[i];
        if(currmoves<k){
            currmoves++;

            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
    }


    ll score=0;

    f(t,0,z+1){
        ll end_idx = k-2*t;

        if(end_idx < 0){
            continue;
        }


        ll base_sum = accumulate(arr.begin(), arr.begin() + end_idx + 1, 0ll);

        ll max_pair = -1e5;
        f(i,0,end_idx + 1){
            if(i+1<n){
                max_pair = max(max_pair, arr[i] + arr[i+1]);
            }
        }


        score = max(score, base_sum +  t*max_pair);

    }

    print(score);

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