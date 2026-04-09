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

    for any odd n the min x=2
    but for even n, need to test the cases as its can be anything cuz as number grows need to check its not div by any other num from its [1,n-1]

    for even n, finding answer is like summing up by going for each [1,n] by listing its divisors and suming its MEX
    

    during the dry run values for few f(x) x->[1,30]
    found that -
    f(i) >= 2, then 1 must divide i
    f(i) >= 3, then 1,2 must divide i  -> lcm(1,2)=2 must be this multiple
    f(i) >= 4, then 1,2,3 must divide i -> lcm(1,2,3)=6 must be multiple of 6
    .... 
    f(i)>=k then i must be multiple of lcm(1...k-1) = L

    so we just count the taoal numbers we recieve from calculation for till L < n


  */


  ll n;cin>>n;

  ll MOD = 1e9+7;
  ll ans=0;


  auto lcm = [&](ll a,ll b){
    if(a==0 or b==0) return 0ll;
    return (a/__gcd(a,b))*b;
  };

  
  ll currlcm = 1;
  for(ll k=1;;k++){
    currlcm = lcm(currlcm, k);

    if(currlcm >n)break;


    ans = (ans + n/currlcm)%MOD;
  
    // print(ans);
  }
  ans += n;


  print(ans%MOD);

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