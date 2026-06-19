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


const bool multipleTestCases = 0; 

void solve(){
  /*

    alternating = no 2 adjacent elemtns equal..
    performing 1 operation only 

    Now, each dups 00 11 is a spot where to gain+1 to our answer...
    by using the endpoint of our flip window.
    if >=2 dups apirs, then  perfectly L+2 answer increase

    if == 1 dup pair, then using 1 endpoint of our flip window, we fix that single pair,
    hence answer increasing to L+1

    if zero dup pair then max lenght is just L


    max upper maximum length - max(n, l+2)

  */

    ll n;cin>>n;
    string s;cin>>s;


    ll L=1;
    f(i,1,n){
        if(s[i] != s[i-1]){
            L++;
        }
    }


    cout << min(n, L+2) <<"\n";

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