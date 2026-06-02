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

    since the naive logic for pi wont work here 
    because of hard constriants.
    we need to calcluate the optimal p value maximum possible for each arr[i];

    let v = ai/p
    if we assume the pmax = ai/v +1


    to be repeatedly finding thebest answer
    we can use priorityqueue to keep the max eletn
    and use it as v
    and updating the priorityque when required;

    
  */

    
    ll n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    
    ll currmin = 2e9;
    
    priority_queue<pll>pq;
    f(i,0,n){
        pq.push({arr[i],arr[i]});
        currmin = min(currmin, arr[i]);
    }


    ll min_diff = 2e9;

    while(true){
        auto top = pq.top();pq.pop();

        // assuming max to be v
        ll v = top.first;
        ll ai = top.second;

        min_diff = min(min_diff, v - currmin);

        if(v == 0){
            // cant divisde by zero
            break;
        }


        ll pmax = ai / v + 1;
        if(pmax > k){
            break;
        }
        
        ll new_v = ai / pmax;
        currmin  = min(currmin, new_v);

        pq.push({new_v, ai});

    }

    print(min_diff);

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