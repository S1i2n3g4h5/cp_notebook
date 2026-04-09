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
    main observation is that since its asking for the number of ways
    and bitmask is go-to-option (another hint is given some conditions and array)
  
    basic implementaion includes looping for choosing subarray elems and then after selection
    doing verification for valid answer
    
  */

    ll n,l,r,x;cin>>n>>l>>r>>x;
    vll p(n);
    f(i,0,n)cin>>p[i];


    ll ans=0;

    for(int mask=0;mask <= (1ll << n); mask++){

        
        // chosing the subset of problems;
        ll total_problems =0, total_difficulty=0;
        ll mn_diff=1e9, mx_diff=0;
        f(i,0,n){
            if((mask >> i) & 1){
                total_problems++;
                total_difficulty += p[i];

                mn_diff = min(mn_diff, p[i]);
                mx_diff = max(mx_diff, p[i]);
            }
        }


        if(total_problems >= 2 and (mx_diff - mn_diff >= x) and total_difficulty >= l and (total_difficulty <= r and total_difficulty>=l)){
            ans++;
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
