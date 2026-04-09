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



const bool multipleTestCases = 0;


void solve(){
    
  int n,k;cin>>n>>k;
  vector<int>arr(n);
  ll ans=0LL;
  f(i,0,n){
    cin>>arr[i];
}
    sort(arr.begin(),arr.end());

    f(i,0,k){
        if(arr[i]<=0)ans+=arr[i];
    }
  print(abs(ans));
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