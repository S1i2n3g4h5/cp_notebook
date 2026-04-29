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
    since for k>=3, answer always 0
    cuz, 
        1st operation - x = ai-aj
        2nd operation - y = ai-aj  (same diff again)
        3rd operation - x-y  ( same diff gets cancelled, hence zero)

    for k=1, double loops works perfectly

    but the complex case is for the k=2;

    but its easy for even thsi once we get the gist of the logic, 
    so its like we do double loop i,j for clacuting  x = arr[j] - arr[i];

    okay then we just find where this diff is localted into the sorted array,
    then try to finding its diff from its just lower arr[i] <= diff   and just upper arr[i]>=diff
        arrlower <= x <= arrupper

    then just find the min diff from these
    cuz the diff is min from the nerest numbers in sorted manner..

  */

    int n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    if(k>=3){
        print(0);
        return;
    }


    sort(all(arr));

    ll res = arr[1] - arr[0];

    f(i,0,n-1){
        res = min({res, arr[i], arr[i+1] - arr[i]});
    }

    if(k==1){
        print(res);
        return;
    }


    // k==2
    f(i,0,n){
        f(j,i+1,n){
            ll x = arr[j] - arr[i];

            
            // simulating the 2nd operation move
            // min(diff - arr[left])
            auto it = lower_bound(all(arr), x);

            if(it !=  arr.end()){
                res = min(res, *it - x);
            }

            if(it != arr.begin()){
                res = min(res, x - *prev(it));
            }

            // res = min(res, x);

        }

    }

    print(res);


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