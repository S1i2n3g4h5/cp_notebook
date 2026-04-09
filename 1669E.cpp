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
    1 approach consists of creating map<vector> for each pair to store its corresponding valid pair then adding it up 
        this will be going for o(n^3) solution but efficient cuz only 2 chars with chars from a to k only


    2nd better optimized observational approach consists of utilizing the freq,counts but will be implementing later on

  */

    int n;cin>>n;
    

    ll cnt1[12][2] = {0};
    map<string, int> full_cnt;
    
    ll ans =0;
    f(i,0,n){
        string s;cin>>s;


        int c1 = s[0] - 'a';
        int c2 = s[1] - 'a';

        ans += cnt1[c1][0] + cnt1[c2][1] - 2*full_cnt[s];
        // print(cnt1[c1][0], cnt1[c1][1]);
        // print(ans);

        // update
        cnt1[c1][0]++;
        cnt1[c2][1]++;
        full_cnt[s]++;
    }


    print(ans);


    
    // vector<vector<int>> cnt(12, vector<int>(12, 0));
    // long long ans = 0;
    
    // for(int i = 0;i < n; ++i) {
    //     string s; cin >> s;
    //     for(int j = 0;j < 2; ++j) {
    //         for(char c = 'a'; c <= 'k'; ++c) {
    //             if(c == s[j]) continue;
    //             string a = s; a[j] = c;
    //             ans += cnt[a[0] - 'a'][a[1] - 'a'];
    //         }
    //     }
    //     ++cnt[s[0] - 'a'][s[1] - 'a'];
    // }
    // cout << ans << "\n";

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
