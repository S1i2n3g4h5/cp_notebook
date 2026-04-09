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

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    int i=0,j=n-1;
    ll a=0, b=0;
    ll just_ate = 0;
    int turns = 0;

    while(i<=j){
        turns++;

        ll curr_ate = 0;
        
        if(turns %2 == 1){
            while(i<=j and curr_ate <= just_ate){
                curr_ate += arr[i];
                i++;
            }
            a += curr_ate;
        }
        else{
            while(i<=j and curr_ate <= just_ate){
                curr_ate += arr[j];
                j--;
            }
            b += curr_ate;
        }

        just_ate = curr_ate;
    }


    print(turns, a,b);

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