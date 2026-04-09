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
    int n;cin>>n;
    vector<ll> a(n),b(n-1),c(n-2);
  
  
    f(i,0,n)cin>>a[i];
    ll currb= a[0];
    
    f(i,0,n-1){
        cin>>b[i];
        currb += a[i+1]-b[i];
    }

    ll currc= b[0];
    f(i,0,n-2){
        cin>>c[i];
        currc += b[i+1]-c[i];
    }

    print(currb, "\n", currc);

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