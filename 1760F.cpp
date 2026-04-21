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
    monotonic property hence binary search
    need to find the maximum k  and range of k is [0,d]

    edge cases - infinity, impossible

    since for the check condition matching up those x total coins over d days, maintinign the k cooldwon
    and since if ther eis somethiign written like `you cant do x for K days` then always think for `cycle of length k+1`

    

  */

    ll n,c,d;cin>>n>>c>>d;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }
    sort(rall(arr));


    ll tot = accumulate(arr.begin(), arr.begin() + (min(n,d)), 0ll);
    if(tot >= c){
        print("Infinity");
        return;
    }
    if(arr[0] * d < c){
        print("Impossible");
        return;
    }


    auto check = [&](ll k) -> bool {
        ll cycle_len = k+1;
        ll tot = 0;

        // f(i,0,d){
        //     if(i%cycle_len < n){
        //         tot += arr[i%cycle_len];
        //     }

        //     if(tot >= c)
        //         return true;
        // }

        
        ll full_cycles = d / cycle_len;
        ll extra_days = d % cycle_len;
        
        f(i,0,min(n,cycle_len)){
            tot += arr[i] * full_cycles;
        }
        
        
        f(i,0,min(n,extra_days)){
            tot += arr[i];
        }

        return tot >= c;
    };


    ll low=0,high=d;
    while(low <= high){
        ll mid = low + (high - low)/2;

        if(check(mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }

    }

    print(low -1);

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