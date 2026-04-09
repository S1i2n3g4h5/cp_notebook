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


const bool multipleTestCases = 0; 

void solve(){
  /*

  */

    ll n;cin>>n;
    vector<pair<ll,ll>>arr(n);
    f(i,0,n)cin>>arr[i].first;
    f(i,0,n)cin>>arr[i].second;



    // -----------------------------
    // only to find the C
    vll x_array;

    f(i,0,n){       
        // a[i] b[i]
        
        ll l=0, h=2e9;
        while(l<h){
            ll mid = l +(h-l)/2;
            
            bool ans = (arr[i].first*mid - arr[i].second) >=0;
            if(ans){
                h= mid;
            }
            else{
                l=mid+1;
            }
        }

        x_array.push_back(h);
    }


    // sorting
    sort(all(x_array));

    // f(i,0,n){
    //     cout << x_array[i] << " ";
    // }

    // cout << "\n";


    ll q;cin>>q;
    while(q--){
        ll C;cin>>C;

        auto it = upper_bound(all(x_array), C);
        print(distance(x_array.begin(), it));
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