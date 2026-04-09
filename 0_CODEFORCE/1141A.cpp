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

    int n,m;cin>>n>>m;
    
    if (m%n>0){
        print(-1);
        return 1;
    }
    else if (n==m){
        print(0);
        return 1;
    }
    
    
    int steps=0;
    ll ratio = m/n;
    while(ratio%2==0){
        steps++;
        ratio>>=1;
    }
    while(ratio%3==0){
        steps++;
        ratio/=3;
    }

    if (ratio == 1){
        print(steps);
    }
    else print(-1);
    
    // if (mxfactor>3){
    //     print(-1);
    //     return 1;
    // }
    
    // print(ans.size());
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