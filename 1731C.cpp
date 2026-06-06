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
    there are few observastion - 
        1. the final xor vlaue of subarray will need ot have unique primes fcators only for being even divsors...

    but couting all subarrays is impossibl due ot constraints...
    so another perspective could be to find those that are not and subtracting from total subarray counts
    that is n(n+1)/2

    and since we know  that for every number the divisor pairs are like
    in pairs alreday for exmaple 12
        -> 1 12, 2 6, 3 4, 6 2

    but for perfect squrees are the only numbers that have odd number of divisors

    ---

    so we boil the questiont to-
    coutning the number of subarray whose XOR sum has odd number dvisor and then subtracting from total subarray;
    odd divisors are those having perfect squre ->. xor sum solutino hint

    there are total 447 perfect squares <=2e5..
    

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    ll total_subarray = n*(n+1)/2;

    vll pf(n);
    pf[0] = arr[0];
    f(i,1,n)
        pf[i] = pf[i-1] ^ arr[i];


    f(i,1,2e5+1){

        if(i*i > 2e5){
            print(i);
            break;
        }

    }

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