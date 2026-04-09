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
    strategy is using 1s and 2s possible 
  */

    int n,k;cin>>n>>k;

    
    ll rem_odd = n- (k-1);
    if(rem_odd%2 >0 and rem_odd%2 == 1){
        print("YES");

        f(i,0,k-1) cout << "1 ";
        cout << rem_odd << "\n";
        return;
    }


    ll rem_even = n-2*(k-1);
    if(rem_even>0 and rem_even%2 == 0){
        print("YES");
        f(i,0,k-1) cout << "2 ";
        cout << rem_even << "\n";
        return;
    }

    print("NO");

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