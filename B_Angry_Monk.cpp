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


const bool multipleTestCases = 1; 

void solve(){
  /*
    operation-
        - pick a[i]>=2, divide inot 2 pieces -> 1,a[i]-1.
          hence numbe rof pieces increase by 1
        - pick a[i], and a[j]=1.... then merge them into single piece. hence pieces decrease by 1

    choose the maximum available
    then merge the number of ones availabe currently then
     focusing onto the leftover ones to split and merge up again

  */

    ll n,k;cin>>n>>k;
    vll arr(k);
    map<ll,ll>fr;
    ll mx=0;
    f(i,0,k){
        cin>>arr[i];
        mx = max(mx, arr[i]);
        fr[arr[i]]++;
    }

    ll ans=0;

    
    // add existing ones..
    if(fr[1]>0){
        ans += fr[1];
        fr.erase(1);
    }

    for(auto [val,cnt] : fr){
        if(val == mx){
            if(cnt == 1){
                // dont do anythign cuz we are try to maximiize this
            }
            else{
                // lots of mx values
                ans += (cnt - 1)*(2*val-1);
            }
        }
        else{
            // other smaller a[i] values
            
            // split n merge
            ans += cnt*(2*val-1);
        }
    }

    if(mx == 1){
        ans--;
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