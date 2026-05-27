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

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

// ______________________________________________________
long long fast_power(long long base, long long power, long long MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if ((int)name.size() > 0) {
        if (fopen((name + ".in").c_str(), "r")) {
            freopen((name + ".in").c_str(), "r", stdin);
            freopen((name + ".out").c_str(), "w", stdout);
        }
    }
}

const bool multipleTestCases = 0; 

void solve(){
  /*

  */

    ll x,y;cin>>x>>y;

    ll ans=0;
    int dir=1;
    int direction_dist=1;

    while(true){
        bool forward = (dir ==1 and x<=y and y <= (x + direction_dist));
        bool backward= (dir ==-1 and y<=x and (x - direction_dist) <= y);
    
        if(forward or backward){
            ans += abs(y - x);
            break;
        }
        else{
            ans += direction_dist*2;
            direction_dist *=2;
            dir*=-1;
        }
    }

    cout << ans;

}


int main(){
  setIO("lostcow"); 
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}