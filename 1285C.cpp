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


const bool multipleTestCases = 0; 

void solve(){
  /*
    since our condition to find the answer, 
    we need the lcm(d,X/d) to be X

    and we know that lcm*gcd=a*b

    when putting all formula values we find that 
    for lcm = X, we need the gcd = 1;

    hence just iterate till root X and find the min possible pari having gcd=1;

  */

    ll n;cin>>n;


    ll mxa=1,mxb=n;

    for(ll i=1ll;i*i<=n;i++){
        if(n%i ==0 and __gcd(i,n/i)==1){
            ll curra = i;
            ll currb = n/i;
            if(curra>currb) swap(curra,currb);

            if(currb < mxb){
                mxa = curra;
                mxb = currb;
            }
        }

    }
    
    print(mxa,mxb);

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