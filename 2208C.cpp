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


const bool multipleTestCases = 1; 

double backtrack(int idx, int n, auto&c, auto&p, auto&memo){
    if(idx == n)
        return 0.0;

    if(memo[idx] > -0.5){
        return memo[idx];
    }

    // 1 - skip
    double skip = backtrack(idx+1, n,c,p,memo);

    // 2 - take
    double multiplyer = 1.0 - (p[idx]/100.0);
    double task = (double)c[idx] + (multiplyer * skip);

    
    memo[idx] = max(skip, task);
    return max(skip,task);

}


void solve(){
  /*
    note down the common factor repeating,   (1-pi/100);   after the task i;

    ig this could be dp problem cuz the initial options vary the answer..
    instead of going from index 0 where havinng any start options, start with ending to decide take or not.
    lets go from backward, where the only optin is either take or leave

  */

    int n;cin>>n;
    vll c(n),p(n);
    f(i,0,n)cin>>c[i]>>p[i];
    vector<double>memo(n,-1.0);


    double ans = backtrack(0,n,c,p,memo);


    cout << fixed << setprecision(10);
    print(ans);

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