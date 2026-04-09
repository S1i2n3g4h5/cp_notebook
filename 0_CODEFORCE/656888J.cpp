#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}



#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = true;


void solve() {

  int n,l,r;cin>>l>>r>>n; 

  /*
  phoenix and towers
  give n blocks of heights h1,2h2 ...
  dont exceed value x he plan to staack n into m sperate blocks  such that diff strictly not more than x
  */

  vector<int> h(n);
  f(i,0,n) cin>>h[i];
  sort(h.begin(),h.end());
  ll ans=0;

  f(i,0,n){
    ll idx= upper_bound(h.begin(),h.end(),h[i]+r)-h.begin();
    idx--;
    if (h[idx]-h[i]>=l and h[idx]-h[i]<=r){
      ans+= (idx - i);
    }
  }
  print(ans);
  
}

 
int main() {
  ios::sync_with_stdio(0);


  cin.tie(0);
  
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;

    
    while(t--){
  
  
      solve();
  
    }
  
    return 0;
}   