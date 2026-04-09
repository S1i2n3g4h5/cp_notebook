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


const bool multipleTestCases = 1; 

void solve(){
  /*
    since brute forcing the way wont result into anyting cuz there is some contrain space which misses this logic

    it also means that - 
        if we got even number of negative signs we can always force those signs to be adjacent and flip those then with this we can easily get 0 negative signs left

    similarly for odd number, even if we have like 1,3,5.... odd signs we can cancel out to remain with 1 neg sign only

  */
    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];
    
    ll tot=0ll;
    ll mn=abs(a[0]);
    ll neg_cnt=0;
    f(i,0,n){
        tot += abs(a[i]);
        mn = min(mn, abs(a[i]));
        neg_cnt += (a[i] < 0);
    }
    
    if((neg_cnt & 1) == 0)
        print(tot);
    else
        print(tot - 2*mn);
    
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
