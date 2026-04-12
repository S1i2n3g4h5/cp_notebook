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

vector<string>powers;

void precompute(){
  for(ll i=0;i<=60;i++){
    powers.pb(to_string(1ll << i));

  }
}

void solve(){
  /*
    basic implemetnion to grediyl check all powers of 2 and find min answer

    more bluntly we ind the common subsequence between the numbers

    so its like if we want to convert 1052 to 1024 we would require 2 moves
    cuz removing 5 then adding 4 at end

    hence the maths is like ->  (string s - matching chars) + (string prime - matching chars)

  */

  string s;cin>>s;

  ll ans=s.size()+1;  


  for(auto p:powers){

    // matching
    int si=0, pi=0;
    int matched=0;

    while(si < s.size() and pi<p.size()){
      if(s[si] == p[pi]){
        matched++;
        pi++;
      }

      si++;
    }

    ll moves = (s.size() - matched) + (p.size() - matched);


    ans = min(ans, moves);

  }


  print(ans);

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  precompute();
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}