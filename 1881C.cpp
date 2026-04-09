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
    since during rotation it follows symmetry
    hence no need to go looping for all i,j in square
    instead we just got for n/2 cuz of symmetry property after rotation which needs to be satisfied.

    90 deg rotation maps - i,j to (j, n-i-1);
    1. i,j
    2. n-1-i,n-1-j
    3. j, n-i-1
    4. n-1-j,i

    needs these 4 pos to be cyclic positions for perfect sq condition

    n changing to max character is just selecting max char from given 4 n summing up diffs with other
  */

    int n;cin>>n;
    vector<string>arr(n);
    f(i,0,n)cin>>arr[i];


    ll ans=0;
    f(i,0,n/2){
        f(j,0,n/2){

            char c1 = arr[i][j];
            char c2 = arr[n-j-1][i];
            char c3 = arr[j][n-i-1];
            char c4 = arr[n-i-1][n-j-1];

            char mx = max({c1,c2,c3,c4});

            ans += mx-c1 + mx-c2 + mx-c3 + mx-c4;

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