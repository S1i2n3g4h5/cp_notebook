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
    so there could be 2 types of scenarious -

    for maxmizing we want as many nuber sof playerrs inot team, hence
    max pairs = sz=n-(m-1)   and   answer = sz*(sz-1)/2

    for the min paris we want to distribute as evenly as possible
    k  =n/m;
    r = n%m

    so this means there are r teams of size k+1
    and (m-r) teams of size k


  */

    ll n,m;cin>>n>>m;

    
    ll ansmin=-1,ansmax=-1;

    
    // minimum
    ll k = (n/m);
    ll r = n%m;

    ansmin = (r * (k*(k+1)/2)) + ((m-r) * (k*(k-1)/2));


    // maximum
    ll mxsz = n -(m-1);
    ansmax = mxsz * (mxsz - 1)/2;


    print(ansmin, ansmax);


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