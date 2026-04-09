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

bool ispow2(ll n){
    if(n==0)return false;
    return (n & (n-1)) ==0;
}

vll powerful;

void solve(){
  /*

    num powerful if there exists d such that   m = 2^d  or m=d!

    since bitmasking kinda very heavy and tle prone
    so lets try finding some observations of how a n can be made using factorial + power of 2

    Since any number can be made using power of 2s, for whcih k = total set bits
    and so to minimize this we required to pairs the set bits with such powerful factorial nums
    as to get the required answer..

    and since the factorials array is small, lets bitmask directly


  */

    ll n;cin>>n;


    // set bits means req for power of 2
    ll ans=__builtin_popcountll(n);

    for(int mask=0;mask<(1ll << powerful.size());mask++){

        ll sm=0;
        ll fact_count=0;
        f(j,0,powerful.size()){
            if((mask>>j)&1){
                fact_count++;
                sm += powerful[j];
            }
        }

        
        if(sm <= n){
            ans = min(ans, fact_count + __builtin_popcountll(n - sm));
        }

    }
    

    print(ans);


}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  

    ll num=6;
    for(int i=4;num<=1e12;i++){
        powerful.pb(num);
        num*=i;
    }



  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}