#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define ll long long
#define ld long double
#define f(i, a, b)          for(ll i = a; i < b; i++)



const bool multipleTestCases = 1;
  

void solve(){
  set<ll>mp;

    for(ll i=1; i<=1e4; i++){
    mp.insert(i*i*i);
  } 


  ll x;cin>>x;

  if(x<=1){
    print("NO");
    return;
  }


  f(i,1,1e4+1){
      if(mp.count(x-i*i*i)){
        print("YES");
        return;
      
    }

  }

  print("NO");
  
  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;   
    
    while(t--){  
      solve();
    }  
    return 0;
}     
