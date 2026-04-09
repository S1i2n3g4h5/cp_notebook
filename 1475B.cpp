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
    since 2021(x) = x(2020) + x;
    so deriving the both 2021,2020 into single equation

    k=x+y;
    n=2020(k) + y;           -> y is remainder from dividing by 2020;
    =>  x = k-y;
    
    => n=2020(q) + r;  
        so k=q so x+y = q      and    y=r 
        x = q-y;
        
    now since x>=0
            q-y>=0
            q>=y
        
    q = n/2020
    r = n mod 2020
  */

    ll n;cin>>n;

    ll q,r;
    q = n/2020;
    r = n%2020;

    if(n<2020 || (q<r)){
        print("NO");
        return;    
    }


    print("YES");


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
