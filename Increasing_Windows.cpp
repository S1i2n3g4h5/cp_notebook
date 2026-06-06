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
    problem boils down to count the number of arrays A of length N
    wiht elemtns 1 to N such that array B defined by Bi = max(ai..ai+k-1) is strictkly increasing

    since we are sliding a window of length k, we cant take a maximum element Bi form 1st window
    to be included into next window, because then the conditioon will become - bi <= bi+1
    which is not possible. (as its clearly mentioned in constraints that bi < bi+1)


    -> max(a1,a2,a3...ak) < max(a2,a3..ak+1) to hold properly.
    -> and this onyl possible if and only if, max(a2..ak+1) = ak+1 becuase this cant override and overlap wiht previsou window which contradicts the condition
    -> thus combining these stuff, we infer that -
        using ak+1 = max(a2,a3...ak+1) -> 
        max(a1,a2...ak) < ak+1 < ak+2 < ak+3


    So this meaning after fixing first K elemtns the remaining elemtns must be strictly increasing order

    ---

    so now lets say for a fixed M,array is made of 2 seaprate parts
    
    -> totalways for a fixed M = ways to build prefix x ways t build suffix

    ---

    and we need to loop over M being the maximum to be fixed elemnt

    and since, 
    total size of our pile lets say 3 (which is target M)
    size of gabage pile = 2 (which is M-1)
    the number of slots in box= 2 (K)


    hence, M^K - (M-1)^K

  */

    ll n,k;cin>>n>>k; 
    
    ll mod = 998244353;


    


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