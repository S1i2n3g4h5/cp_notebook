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
  
    moving table and to minize the dist moved, try moving such that tables get stick as close to each other through borders;

    (x2-x1) + w <= W     and  (y2-y1) + h <= H
    
    moving top    - h-y1 <= k
    moving bottom - y2-(H-h) <= k
    
    
    vice versa for left,right...
    
    */


    ll W,H,x1,y1,x2,y2,w,h;cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;


    ll ans =-1;
    
    ll current_w =  x2 - x1;
    ll current_h = y2 - y1;
    

    if(current_w + w <= W){
        ans = min(max(0ll, w-x1), 
                     max(0ll, x2 - (W-w)));
    }


    if(current_h + h <= H){
        ll res = min(max(0ll, h- y1), 
                     max(0ll, y2 - (H-h)));
        
        if(ans == -1 or res < ans)
            ans = res;
    }


    if(ans == -1){
        print(-1);
        return;
    }


    cout << fixed << setprecision(9);
    print((double)ans);
    
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
