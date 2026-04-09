/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 1; 


void solve(){
  /*
    
  if there is at least one adjacent pair of identical characters in the circle,
    we can achieve K+1 blocks...
  
    othrwise (all adjacent pairs are different), we achieve K blocks.
  */

    int n;cin>>n;
    string s;cin>>s;


    bool possible_to_cut_at_same = false;
    
    int diffs = 0;
    f(i,0,n){
        if(s[i] != s[(i+1)%n]){
            diffs++;
        }
        else{
            possible_to_cut_at_same = true;
        }
    }

    
    if(possible_to_cut_at_same){
        print(diffs + 1);
    }
    else{
        print(diffs);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
