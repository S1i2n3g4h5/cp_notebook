/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
  int n,m;cin>>n;
  vector<int>boys(n);
  f(i,0,n)cin>>boys[i];
  cin>>m;
  vector<int>girls(m);
  f(i,0,m)cin>>girls[i];



  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());

  int ans=0;
  int i=0,j=0;
  while(i<n and j<m){

    if(abs(boys[i] - girls[j]) <= 1){
      i++;
      j++;
      ans++;
    }
    else{
      if(boys[i] > girls[j]){
        j++;
      }
      else{
        i++;
      }
    }
  }

    print(ans);

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}