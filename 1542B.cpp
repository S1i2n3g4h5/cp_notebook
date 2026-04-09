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
    since 1 is alread in the set

    2 operations happens for new numbers -
      - x * a
      - x + b
    and these 2 new elements are also added then


    if you run some dry runs you find that, 
    its kind of thisformula only - 
      =>   n = a^k + (m*b)

    similarly even if we do (b+1)*a  formula we get  a+ab which is still in our genralized form


    hence we need to verify if n can be fit into the formula for answer to exists or not

    but we can generalize the code into checkng 2 things that is
    checking if the a=1 and another case for the a>1

  */

  ll a,b,n;cin>>n>>a>>b;


  if(a == 1){
    // n =  1 + (m*b)
    if((n - 1) % b  == 0){
      print("Yes");
    }
    else{
      print("No");
    }
  }
  else{
    // n =  a^k  + (m*b)
    ll current_pow = 1;

    while(current_pow <= n){    
        if((n - current_pow)%b == 0){
          print("Yes");
          return;
        }

        current_pow *= a;
    }
    print("No");

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