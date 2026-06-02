/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
//For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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
    its like on every day's morning the bacteria either split or stay same. but after the day night's all alive backteria gets +1
    
    on obsering the sums received, its forming power of 2

    s = 1+2+4...2^d
    lets 2s = 2+4+8..2^d+2^(d+1)
    2s-s = ...
    s = 2^(d+1) - 1

    this s represent the maximum mass formula to be used to determine exact days d we need

    ----

    if we get the max power of 2 >= n, we find these number of days requried.
    but when power of 2 > n  we get some in excess which needs to be adjusted back
    so instead of guesing the exact numbers we ust put the nums inot liskt and find them

    like [2^1 -1, 2^2-1.....2^d-1]

    * another observation like, the series musst be increasing cuz we cant un-split somethign done, it will contnue to grow even after split or no split
    * maximum they can double each day 

    so wiht these 2 observations we find, the differences of the power of 2s list we made + insert the n
    must be increasing sequency of differences
    and another conditions being- 
        night2 increase <= 2*(night1 increase)
    so that is why no next difference cna be more thatn 2(arr[i-1])
    
  */

    ll n;cin>>n;


    vll arr;
    for(ll i=1;i<=n;i*=2){
        arr.pb(i);
        n -= i;
    }
    

    if(n > 0){
        arr.pb(n);
        sort(all(arr));
    }
    

    print(arr.size()-1);
    f(i,1,arr.size()){
        cout << arr[i] - arr[i-1] << " ";
    }

    cout << "\n";


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