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
    we will try to brute force optimally
    by making a minimized and c maximized

    so just finding 2 variables a,b such that  n/(ab) should not be equal to 1,a,b  then answer feasible
  */

    ll n;cin>>n;


    int a=-1,b=-1,c=-1;

    for(int i=2;i*i<=n;i++){ 
        if(n%i==0 and a==-1){
            a=i;
            n=n/a;
            break;
        }
    }
    
    for(int i=2;i*i<=n;i++){
        if(n%i == 0 and b==-1 and i!=a){
            b=i;
            n=n/b;
            break;
        }
    }



    if(n==1 or a==-1 or b==-1  or (a==n or b==n)){
        print("NO");
    }
    else{
        print("YES");
        print(a,b,n);
    }
    

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
