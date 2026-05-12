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
    since on matter how we slice the the string for "A" mutiplicaiton 
    we get same result, like if we slice single chars at a time then its (l=10)- 1a +1a+1a...1n = 10a
        if we delte whole string -> l=10 -> 10a

    there no space for optimization into "a" so "a" acts as constant which cant be changed

    ---
    
    now coming for "b" variable, cuz its added per operation hence optimizing here
    1. if b is positive we just wnat as many b hence delting one at a time -> n*b
    2. if b is negative we want few b's as possible -> so grouping chars and deleting, hence (m/2+1)    
        even though m is denoting the total groups,we doing m/2+1 cuz after delteing 1 group, other groups merge, hence the operatison are not tooal groups but m/2 +1
        

  */

    int n,a,b;cin>>n>>a>>b;
    string s;cin>>s;
      

    int m = unique(all(s)) - s.begin();

    print(n*a + max(n*b, (m/2+1)*b));



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