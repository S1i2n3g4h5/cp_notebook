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
    since the overall product remains constant as (ai/x)*(aj*x) = ai*aj;

    core observation is in the prime factorization, like just moving the prime factors here or there only
    to make all the count of prime factors equal..

    hence the count of total prime counts must be divisible to the total array elemsn 

  */

    ll n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];

    
    map<int,int>cnts;
    f(i,0,n){

        ll tmp = a[i];
        for(ll j=2;j*j <= tmp;j++){
            while(tmp%j == 0){
                cnts[j]++;
                tmp/=j;
            }
        }
        if(tmp>1)
            cnts[tmp]++;

    }


    for(auto p:cnts){
        if(p.second < n or p.second % n != 0){
            print("NO");
            return;
        }
    }

    print("YES");

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