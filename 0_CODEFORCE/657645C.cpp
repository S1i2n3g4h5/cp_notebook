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



const bool multipleTestCases = false;

bool solve(){
    ll n;cin>>n;
    map<ll, ll> arr;
    f(i,0,n + (n-1) + (n-2)){
        ll tmp;cin>>tmp;
        arr[tmp] = (arr[tmp] +1)%3;
    }
  
    for(auto& p:arr){
        if ( p.second  >0 )print(p.first);
    }

    return 1;
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