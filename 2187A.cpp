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
#define debug(x) cout<<#x<<" = "<<x<<ln
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
    if already sorted then -1

    else 
        through swapping the sorting is possible
        but need to clc the min k possible for each index by checking the dist from min elemen n max elem available
  
  */

    int n;cin>>n;
    vll a(n);
    ll mn=1e9,mx=0;
    f(i,0,n){
        cin>>a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    if(is_sorted(all(a))){
        print(-1);
    }
    else{

        vll b=a;
        sort(all(b));


        int k=1e9;
        f(i,0,n){
            if(a[i] != b[i]){
                int curr_mx_reach = max(abs(a[i] - mn), abs(a[i] - mx));
                
                k  = min(k, curr_mx_reach);
            }
        }


        print(k);

    }

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
