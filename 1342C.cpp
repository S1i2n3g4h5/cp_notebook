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
    since l,r goes till 1e18, so single loop for each not possible
    need some trick
    
    since the given equation shows periodicity like repeating like cycles after num fixed k nums
    
    k = LCM(a,b);

    we ca use prefix sm to calcualte and then fix it.
  */

  ll a,b,q;cin>>a>>b>>q;

    
    ll lcm = (a*b)/__gcd(a,b);
    vll pref(lcm+1,0);
    f(i,0,lcm){
        pref[i+1] = pref[i] + (((i%a)%b) != ((i%b)%a)  ? 1:0);
    }


    // print((a*b)/__gcd(a,b));
    while(q--){
        ll l,r;cin>>l>>r;

        // cout << full_cycle * pref[l] + pref[rem_cycle + 1] << " ";

        ll l_full_cycle = (l-1) / lcm;
        ll l_rem_cycle = (l-1) % lcm;
        ll l_ans = (l_full_cycle) * pref[lcm] + (pref[l_rem_cycle + 1]);


        ll r_full_cycle = (r)/lcm;
        ll r_rem_cycle = r%lcm;
        ll r_ans = (r_full_cycle) * pref[lcm] + (pref[r_rem_cycle + 1]);


        cout << r_ans - l_ans << " ";

    }
    cout <<"\n";

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
