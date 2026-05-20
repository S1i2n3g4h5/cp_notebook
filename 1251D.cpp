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
    binary search intuition
    cuz if we fixate some median which satisfy then all those median-1 must also be working

    the basline salary must be like all lower bound sum to check <=S else -1


    li>= x- > This means emplyoee already earns more like if thought of x but alrady earnign li>=x

  */

    ll n,s;cin>>n>>s;
    vector<pll>arr(n);

    f(i,0,n){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(all(arr), [&](auto a, auto b){
        return a.first > b.first;
    });


    auto check = [&](ll x){
        ll curr=0;
        int curr_ge_x=0;
        ll target = (n+1)/2;

        vll valids;


        f(i,0,n){
            if(arr[i].first >= x){
                curr_ge_x++;
                curr += arr[i].first;
            }
            else if(x <= arr[i].second){
                // could be boosted...
                valids.pb(arr[i].first);
            }
            else{
                curr += arr[i].first;
                
            }  
            
        }


        // enoguh people >= x with their minimums?
        if(curr_ge_x >= target){
            for(auto val:valids)
                curr += val;

            return curr <= s;
        }


        // how muhc more peopel?
        ll need = target - curr_ge_x;
        if(valids.size() < need)
            return false;


        sort(rall(valids));


        f(i,0,valids.size()){
            if(i < need){
                // bosting the lowest
                curr += x;
            }
            else{
                curr += valids[i];
            }
        }

        return curr <= s;

    };


    ll low=1, high=2e9;
    while(low<=high){
        ll mid = low + (high- low)/2;

        if(check(mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }


    print(low-1);

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