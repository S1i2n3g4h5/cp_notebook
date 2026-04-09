#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


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



// ______________________________________________________
const bool multipleTestCases = 1;


void solve(){
  /*

  */
    
    ll n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];

    ll sm = accumulate(arr.begin(), arr.end(), 0ll);

    auto sq_search = [&](ll sm){
      ll l=0,h=1e9;
      while(l<=h){
        ll mid = l + (h-l)/2;
        if(mid*mid == sm)return true;
        else if(mid*mid < sm)
          l =mid+1;
        else 
          h= mid-1;
      }
      return false;
    };

    bool res = sq_search(sm);

    if(res)
        print("YES");
    else    
        print("NO");

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
