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

  constraints small enoguh for brute force iwht o(n^2)

  obs1 -> placing drain on the lowest cell of any column then only we get max water possible drained

  so we find that for any drain cell we will be getting the max height available then subtracting with total column height of environment
  which will provide the total water block cells to be collected -
    (r-l+1) * (h - a[i])
    here h represents the max height possible

    cuz -    (h-a[i]) given water collected from column k
    and using (r-l+1)  cuz water can only drain down to level a[i], anything below that is blocked by dirt i in column i;
    so each column contribute exactly the same vertical slice

  this is for single drain setting.
  for double drains we cna try the splitting strategy to split array and put drains both
      

  */

  ll n,h;cin>>n>>h;
  vll a(n);
  f(i,0,n)cin>>a[i];

  


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