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


const bool multipleTestCases = 0; 

void solve(){
  /*
  
    to find x,y,z  such that x*y*z = n cuz 
        w/x, h/y, d/z will be integers completely

    x = gcd(n,w);

    since we need x to divide both n and w, we try to give as much n to w dimension
    then its just greedy gcd for leftover dimensions

  */

    ll w,h,d,n;cin>>w>>h>>d>>n;

    // print(__gcd(n,w));
    
    ll x,y,z, a,b,c;

    
    x = __gcd(n,w);
    a=x;
    n = n/x;

    y = __gcd(n,h);
    b=y;
    n = n/y;

    z = __gcd(n,d);
    c=z;
    n = n/z;


    
    if(n<=1){
        print(a,b,c);
    }
    else
        print(-1);


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
