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

  */

    ll n,p;cin>>n>>p;
    vector<ll>a(n),b(n);
    for(auto&x:a)cin>>x;
    for(auto&x:b)cin>>x;

    vector<pair<ll,ll>> arr;
    f(i,0,n)arr.pb({b[i],a[i]});
    sort(all(arr));


    ll remaining =n-1;
    ll cost=p;
    for(auto &[b,a]:arr){
        if(remaining == 0)
            break;


        if(b >= p) break;

        ll use = min(a, remaining);
        cost += use*b;
        remaining -= use;
    }
    
    print(cost + remaining*p);

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