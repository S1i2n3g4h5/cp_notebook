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
    since we know this quesiton smells binary search regarding it we can do it easily. 

    we cna test the code for cehcking if given x benches can be fitted all and conintue downgrading(low) until we foudn the min bench length

for example let bench sace be 2
then pattern looks like   (PP_) (PP_) (PP_)   -> here P=placed   and    _= empty spot

    empty spots = m/(l+1)
    maxdesk per row = m - m/(l+1);

    total capcity = n * maxdesk per row

    and this things total_capcity >= k then only its valid

    n = rows
    m = colmns
    k = people

  */

    ll n,m,k;cin>>n>>m>>k;


    auto check = [&](ll x) -> bool {
        ll empty = m / (x+1);
        ll filled = m - empty;

        return n*filled >= k;

    };


    ll l=1,h=m;
    while(l<=h){

        ll mid = l+(h-l)/2;

        if(check(mid)){
            h=mid-1;
        }
        else{
            l=mid+1;
        }


    }


    print(h+1);

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