/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
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
    Wait, if I match two same chars, they become *.
    Then the chars that were outside them become adjacent.
    This is just stack matching. 
    Like (()) but with 'a' 'b' etc.
    
    // first thought: just check if all counts are even?
    // no, abab is NO but counts are even.
    // so it must be about the order.
    
    Greedy stack should work because if there's any way to win, 
    there must be an adjacent pair to pick.
  */

    int n; cin >> n;
    string s; cin >> s;
    
    vector<char> st;
    for(char c : s) {
        if(!st.empty() && st.back() == c) {
            st.pop_back();
        } else {
            st.pb(c);
        }
    }
    
    if(st.empty()) print("YES");
    else print("NO");
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
