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
    n*m table consisting of build where value = i*j

       1  2  3  4  5
    1  1  2  3  4  5
    2  2  4  6  8  10
    3  3  6  9  12 15
    4  4  8  12 16 20


    since building the whole table doesnt seem very feasible, 
    we can use binary search maybe cuz the values in tables increase as we go rihgt and hence
    binary search can keep a counter of how many done

    i*j <= X
    j <= X/i   ->    count of such number in row i is -> min(m, x/i);



  */

    ll n,m,k;cin>>n>>m>>k;


    auto check = [&](ll x){
        ll tot=0;
        f(i,1,n+1){
            tot += min(m, (ll)x/i);
        }

        return tot >= k;
    };

    

    ll low=1,high=n*m;
    while(low<=high){
        ll mid = low + (high-low)/2;

        if(check(mid)){

            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    print(high +1);
    
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