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
    initally all colored RED
    choose k elemtns paint BLUE

    since the conditon given, the color propagates itself, afterk=1 to its left right simulatniously autmatically

    hence we will need to color strategicaly to color the hwole array proeprly..

    Hidden catch -
        total answe = SUm fo K chosen + Last colored vlaue


    hence for the k=1 case,
        we need to make sure the value we color is max possilbe
    for k>1
        checking for top k+1 elemtns only
    
  */

    ll n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    if(k==1){
        ll ans = arr[0] + arr[n-1];

        f(i,1,n-1){
            ans = max({ans, arr[i]+arr[0], arr[i]+arr[n-1]});
        }

        cout << ans << "\n";

        return;
    }
    
    
    
    sort(all(arr));


    ll ans=0;
    ll cnt=0,pos=n;

    while(cnt<k+1 and pos>0){
        ans += arr[--pos];

        cnt++;
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