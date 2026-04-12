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
    since we need to find the max diff, we loop over all k values
    and ofcourse k can be just 1 to n but instead those divisors of n only

    cuz then only its possible to load full trucks


    wihtout changing order, we do it the cool way using prefx sums ..... :)

  */

    ll n;cin>>n;
    vll arr(n);

    f(i,0,n)cin>>arr[i];

    
    // ll ans=-1;
    // f(d,1,n+1){

    //     if(n%d == 0){

    //         ll mx = -1e18, mn = 1e18;
    //         for(int i=0;i<n;i+=d){
    //             ll sm =0;
                
    //             for(int j=i;j<i+d;j++){
    //                 sm += arr[j];
    //             }

    //             mx = max(mx, sm);
    //             mn = min(mn, sm);
    //         }


    //         ans = max(ans, mx - mn);

    //     }

    // }

    // print(ans);


    f(i,1,n){
        arr[i] += arr[i-1];
    }

    ll ans=0;
    f(k,1,n){

        if(n%k == 0){

            ll mx=-1, mn = -1;

            for(int i=0;i<n; i+=k){
                int L = i;
                int R = i + k - 1;

                ll weight;
                if(i==0)
                    weight = arr[R];
                else
                    weight = arr[R] - arr[L - 1];

                if(mx == -1 or weight > mx) mx = weight;
                if(mn == -1 or weight < mn) mn = weight;

            }

            ans = max(ans, mx - mn);

        }

    }

    print(ans);

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