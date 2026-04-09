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


const bool multipleTestCases = 0; 


void solve(){
  /*
  
  */
  
  int n,q;cin>>n>>q;
  vll a(n);
  f(i,0,n)cin>>a[i];

  
    vll up(n),down(n);
    up[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<=a[i+1] )
            up[i]=up[i+1];
        else
            up[i] = i;
    }
    down[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]>=a[i+1])
            down[i]=down[i+1];
        else 
            down[i] = i;
    }


    f(i,0,n)cout << up[i] <<" ";
    cout<<"\n";
    f(i,0,n)cout << down[i] <<" ";
    cout<<"\n";


  while(q--){
    ll l,r;cin>>l>>r;
    l--;r--;


    ll peak = up[l];
    ll end = down[peak];

    if(end >= r){
        print("Yes");
    }
    else{
        print("No");
    }
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
