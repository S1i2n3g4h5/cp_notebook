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

    teacher pair score > student pair score
    constraints a little tight so find something in o(n logn) or less 

     exploit the constraint given that is   ai+aj > bi+bj
     change it to ai-bi > bj-aj
                => ai-bi  + aj-bj  > 0

                -> let c1 =ai-bi        c2 = aj-bj
                =>   c1>-c2

  */

    int n;cin>>n;
    vector<pair<ll,ll>>arr(n);
    f(i,0,n)cin>>arr[i].first;
    f(i,0,n)cin>>arr[i].second;


    vll diff(n);
    f(i,0,n){
        diff[i] = (arr[i].first - arr[i].second);
    }


    sort(all(diff));

    ll ans=0;
    f(i,0,n){
        if(diff[i] > 0){
            // ans += i;

            ans += i - distance(diff.begin(), upper_bound(all(diff), -diff[i]));

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