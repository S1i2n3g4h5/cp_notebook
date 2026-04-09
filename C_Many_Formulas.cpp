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

vll arr;

ll explore(int idx, const string& s, ll current_val, ll total_sum) {
    if (idx == s.size()) {
        return total_sum + current_val;
    }

    int digit = s[idx] - '0';

    ll res = explore(idx + 1, s, current_val * 10 + digit, total_sum);


    if (idx > 0) {

        res += explore(idx + 1, s, digit, total_sum + current_val);
    }

    return res;
}

void solve(){
  /*

    since constraints small, its easy to use dp or bitmasks to explore all options

  */

    string s;cin>>s;

    print(explore(0,s,0,0));


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