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
    Brute force is easy so going with maths way...

    since the constraint is that to make them equal and we can only
    make them equal to min element aavialabe

    so all  numsb must be divisible by min(a,b,c);
    and another thing is calcualting the cuts req
  */

    ll a,b,c;cin>>a>>b>>c;

    ll mn = min({a,b,c});

    if(a%mn != 0 or b%mn!=0 or c%mn!=0){
        print("NO");
        return;
    }
    

    ll total_cuts = (a/mn-1) + (b/mn-1) + (c/mn-1);
    if(total_cuts <= 3){
        print("YES");

    }
    else{
        print("NO");
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
