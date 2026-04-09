/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


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



// ______________________________________________________
const bool multipleTestCases = 1;


void solve(){
  /*

  */

  ll n,k;cin>>n>>k;
  vector<ll>a(n),t(n);
  f(i,0,n)cin>>a[i];
  f(i,0,n)cin>>t[i];


    ll currsum=0;
    int i=0;
    int mxlen = 0;
    f(j,0,n){
        if(j>0 and t[j-1]%t[j] != 0){
            i=j;
            currsum=0;
        }

        currsum += a[j];
        while(currsum >k and i<=j){
            currsum -= a[i];
            i++;
        }


        if(currsum <= k){
            mxlen = max(mxlen, j-i+1);
        }
    }

    print(mxlen);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
