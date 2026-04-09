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

    greedy 2pointer search

  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    sort(all(arr));
    
    
    ll bluesm = arr[0] + arr[1];
    ll redsm = arr[n-1];


    if(redsm > bluesm){
        print("YES");
        return;
    }


    int i=2;
    int j=n-2;
    while(i<j){
        bluesm += arr[i];
        redsm += arr[j];

        if(redsm > bluesm){
            print("YES");
            return;
        }
        i++;
        j--;
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