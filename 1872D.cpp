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

    since the score is just sum pf pi (i%x==0) - sum of pi with i%y==0
    and for overlaping indexe both will cancel out so it doent really matter which values come into overlapping as they will entualyl cancel out

    let sx = div by x not y
    let sy = div by y not x

    and overlapping are lcm(x,y);

    for pos take largest nums - this can we taken through ap formula directly
    for neg take smallest nums - n*(n+1)/2

  */

    ll n,x,y;cin>>n>>x>>y;


    ll common = n / ((x/__gcd(x,y))*y);
    ll sx = (n/x) - common;
    ll sy = (n/y) - common;

    
    ll pos = (n + (n - sx + 1)) * sx / 2;
    ll neg = (sy*(1 + sy))/2;

    print(pos - neg);

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