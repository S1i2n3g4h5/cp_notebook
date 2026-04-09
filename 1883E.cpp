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

    trying both ways, direct bits maths calcl idff
    and implementaton diff 
  
  */

    ll n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];


    auto get_msb = [](ll x){
        if(x==0) return 0;
        return 63-__builtin_clzll(x);
    };


    ll curr_ops=0,ans=0;
    f(i,1,n){
        int bits_p = get_msb(a[i-1]);
        int bits_c = get_msb(a[i]);

        int diff = bits_p - bits_c;

        if(diff >=0 ){
            if(a[i-1] > (a[i] << diff))
                diff++;
        }
        else{
            if((a[i-1] << (-diff)) > a[i]){
                diff++;
            }
        }

        curr_ops = max(0ll, curr_ops + diff);
        ans += curr_ops;

    }

    print(ans);

    // f(i,1,n){
    //     ll p= a[i-1];
    //     ll c=a[i];
    //     ll diff=0;

    //     if(p>c){
    //         while(p > c){
    //             c<<=1ll;
    //             diff++;
    //         }
    //     }
    //     else{
    //         while(p*2<=c){
    //             p<<=1ll;
    //             diff--;
    //         }
    //     }

    //     curr_ops = max(0ll, curr_ops + diff);
    //     ans += curr_ops;

    // }


    // print(ans);

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