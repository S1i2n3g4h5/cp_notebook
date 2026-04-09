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
    putting as many balls as possible inot k buckets, but must follow 3 strct rules-
    - no duplicates in same group
    - perfect balance (same number of baals after end for each bucket)
    - maximze the total bals in all buckets combined 

    obs1 =>
    no number can be painted more than k times, cuz its rules to have no duplicate in buckets of same number
    so we firs group by value all numbers then cap at K  as we stated.

    so we also colect all these capped indexes which gives us the desired result of those bi>0
  

    obs2 -> need to maximize the total number of ball sin bucket and not the total score form each bucket


    obs3 -> for keeping sure that no duplicates come into single bucket we use this clever trick-
        pputting all idxes into single arra and capping them

  */

    ll n,k;cin>>n>>k;
    vll arr(n);
    map<ll,vll>freq;
    f(i,0,n){
        cin>>arr[i];

        // capping freq at k
        if(freq[arr[i]].size() < k){
            freq[arr[i]].pb(i);

        }
    }


    vll all_vals;
    for(auto x:freq){
        for(auto i:x.second){
            all_vals.pb(i);
        }
    }


    ll max_tot_count_bucket = (all_vals.size()/k)*k;
    vll ans(n,0);

    f(i,0,max_tot_count_bucket){
        /*
            since we know that we capped the freq of each number at k only, we can easily grouped them 
            so no ned to get tension for this duplicates coming, as we already got a good distribution
            which is already colored just need to assign the colorNmber
        */

        ans[all_vals[i]] = (i%k)+1;

    }



    f(i,0,n)cout << ans[i] << " ";
    cout << "\n";

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
