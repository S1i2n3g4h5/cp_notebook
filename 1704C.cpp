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
    we need to focus on saving the max houses which measn if the virus is as far as away hence we take time to solve this thiing

    hence will be required to find the gaps values and solve for the max gap possibel
    and trying to simulate till how many hoses will b esaved, cuz 1 infection affecting 2 houses nearby 


  */

    ll n,m;cin>>n>>m;
    vll arr(m);
    f(i,0,m)cin>>arr[i];

    sort(all(arr));

    vll gaps;
    f(i,1,m){
        gaps.pb(arr[i] - arr[i-1] - 1);
    }
    gaps.pb((n - arr[m-1]) + arr[0] -1);


    sort(rall(gaps));


    int saved=0;
    int curday=0;

    f(i,0,gaps.size()){
        ll diff = gaps[i] - 2*curday;


        if(diff <= 0){
            break;
        }
        else{
            if(diff == 1 or diff==2){
                saved++;
                
                curday++;
            }
            else{
                saved += (diff - 1);

                curday += 2;
            }
        } 


    }


    print(n - saved);

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