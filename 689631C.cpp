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

  */
    
    ll n;cin>>n;
    vll arr(n);

    ll mn = 2e9, mx=-1;
    f(i,0,n){
        cin>>arr[i];
        mn = min(mn, arr[i]);
        mx = max(arr[i], mx);
    }


    if(mx ==mn){
        print(0);
        return;
    }
    else if(mn == 1){
        print(-1);
        return;
    }


    vector<pair<ll,ll>> ans;
    while(1){
        ll mn_idx= 0,mx_idx=0;

        f(i,1,n){
            if(arr[i] < arr[mn_idx])
                mn_idx=i;
            if(arr[i] > arr[mx_idx]){
                mx_idx = i;
            }
        }
        
        if(mn_idx == mx_idx)break;
        
        
        ll next = (arr[mx_idx] + arr[mn_idx] - 1)/arr[mn_idx];
        print(mn_idx, mx_idx,next);
        
        // arr[mn_idx] = next;
        arr[mx_idx] = next;

        ans.pb({mx_idx+1, mn_idx+1});   
        // cout << ans.back().first << ans.back().second << "\n";

    }


    // print(ans.size());

    // for(auto x:ans){
    //     print(x.first, x.second);
    // }


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
