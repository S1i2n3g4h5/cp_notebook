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
  
  */

    int n,q;cin>>n>>q;
    vll a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];
  
 
    a[n-1] = max(a[n-1], b[n-1]);
    for(int i=n-2;i>=0;i--){
        a[i] = max(a[i], max(b[i], a[i+1]));
    }
 
    vll pf(n);
    pf[0] = a[0];
    f(i,1,n){
        pf[i] = pf[i-1] + a[i];
    }


    while(q--){
        int l,r;cin>>l>>r;
        l--;r--;
 
 
        if(l==0){
            cout << pf[r] << " ";
        }
        else{
            cout << pf[r] - pf[l-1] << " ";
        }
 
    }
    cout << "\n";
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
