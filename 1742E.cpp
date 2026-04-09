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

void solve(){
  /*
    baisc prefix binary search based

    need to store the max reachable steps too for indexing later on for the final result

  */

    ll n,q;cin>>n>>q;
    vll a(n);
    f(i,0,n)cin>>a[i];


    vll pfmax(n);
    pfmax[0] = a[0];
    f(i,1,n)
        pfmax[i] = max(pfmax[i-1], a[i]);

    f(i,1,n){
        a[i] += a[i-1];
    }


    while(q--){
        ll x;cin>>x;

    
        auto it = upper_bound(all(pfmax), x);

        if(it == pfmax.begin()){
            cout << 0 << " ";
        }
        else{
            cout << a[distance(pfmax.begin(), prev(it))] << " ";
        }
    }
    cout<<"\n";

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