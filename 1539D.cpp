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

    as we got the prices, we need to sort out to get the min price discount first

    and to gather till that, we will also make purchase from the right side 

  */

    ll n;cin>>n;
    vector<pll>arr(n);
    f(i,0,n)cin>>arr[i].second>>arr[i].first;


    sort(all(arr));


    ll cost=0,curr=0;
    int l=0,r=n-1;
    while(l<=r){
        // if(l==r){
        //     ll need = max(0ll, arr[l].first - curr);
        //     ll fullprice = min(arr[l].second, need);

        //     cost += fullprice*2;
        //     arr[l].second -= fullprice;

        //     cost += arr[l].second*1;
            
        //     break;
        // }


        if(curr >= arr[l].first){
            // threshold met, buy at discount

            cost += arr[l].second * 1;
            curr += arr[l].second;
            l++;
        }
        else{
            ll need = arr[l].first - curr;
            ll take = min(need, arr[r].second);

            cost += take*2;
            curr += take;
            arr[r].second -= take;

            if(arr[r].second == 0)
                r--;
        }
    }

    print(cost);
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