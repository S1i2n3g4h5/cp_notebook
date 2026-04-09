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
  
    first task is to find the msb bit set from given array values
    
    then using the k ops on the msb, msb-1 ... so on until k runs out to maximize the AND value

    first lets count the total unset bits available for each bits

  */

    int n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    
    vll cnt(31,0);
    f(i,0,n){
        for(int bit=30;bit>=0;bit--){
            if(!((arr[i] >> bit) & 1)){
                cnt[bit]++;
            }
        }
    }


    ll ans=0;
    for(int i=30;i>=0;i--){
        if(cnt[i] <= k){
            k -= cnt[i];
            ans += (1<<i);
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
