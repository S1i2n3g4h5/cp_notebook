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
    since the question gave and formula or equation to satisfy for goood condition

    on playing with it using prefix we find that

      summation (ai) = prefix[r] - prefix[l-1];

      and given equation - summation (ai) = r-l+1
          
      so       =>  prefix[r] - prefix[l-1] = r-l+1
                   prefix[r] - r    =   prefix[l-1] - (l-1)

            this equation means just finding those having   <  pref[i] - i  >
      so its just prefix map variation <2sum>

  */

  int n;cin>>n;
  string s;cin>>s;


    map<ll,ll>freq;
    freq[0] =1;   
    
    ll ans=0;
    ll pref=0;

    f(i,1,n+1){
        pref += (s[i-1] - '0');

        ans += freq[pref - i];
        freq[pref-i]++;

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
