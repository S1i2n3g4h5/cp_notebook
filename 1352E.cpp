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
    main constraint is memory and time both.

    obs->   ai<=n  so we can us earray to store freq and then generating efficient subarray
  */

  int n;cin>>n;
  ll mn=n+1, mx=0;
  vll arr(n);
    vector<int>freq(n+1,0);
  f(i,0,n){
    cin>>arr[i]; 
    freq[arr[i]]++;
    mn = min(mn, arr[i]);
    mx = max(mx , arr[i]);  
  }

  
  int ans=0;
  f(i,0,n-1){
    int sm=0;
    int cnt=0;
    f(j,i,n){
        cnt++;
        sm += arr[j];
        
        if(sm >mx)break;
        
        // accumulate atleast 2 elements
        if(cnt < 2)continue;

        if(freq[sm] > 0){
            ans += freq[sm];
            // ans ++;
            freq[sm] = 0;
        } 
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