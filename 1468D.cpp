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

    since the answer is bounded into linear zone that is either left or right and will definately end with fixed boundary
    so the answer is there which can be found through searching ..

    but also we found that binary search here, cuz if bandit lit up X cracker then he must have lit X-1 crakcer too...


    max limit oon crackers is   high = min(m, |a-b|-1)
        this denotes that either the limit end when you use all crackers or the distacne between guard and you is less (~turns can crack all crackers)

    */

    ll n,m,a,b;cin>>n>>m>>a>>b;
    vll cracker(m);
    f(i,0,m)cin>>cracker[i];

    sort(all(cracker));


    auto check = [&](ll x){
        if (x==0) return true;


        ll T;
        if(a>b) T = n-b;
        else T = b-1;


        f(i,0,x){
            // pickig the smallest x crackers
            // and among the selcted start by cracking the largest ones
            if(i+1+cracker[x-i-1] > T) return false;
        }

        return true;
    };  


    ll ans=0;
    ll low=0,high=min(m, abs(a-b)-1);
    while(low<=high){
        ll mid = low + (high-low)/2;

        if(check(mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }

    }

    print(ans);


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