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

    simple obs is that to check the msb of 2 ai,aj
    so if both set at same position then AND >XOR  else AND<XOR

  */

    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];


    vll bits(32,0);
    f(i,0,n){
        int highest_bit=0;
        for(int j=30;j>=0;j--){
            if((a[i]>>j)&1){
                highest_bit = j;
                break;
            }
        }

        bits[highest_bit]++;

    }


    ll ans=0;
    f(i,0,32){
        ans += bits[i]*(bits[i]-1)/2;
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