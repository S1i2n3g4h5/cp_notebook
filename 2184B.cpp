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



const bool multipleTestCases = 1;


void solve(){
  
    ll s,k,m;cin>>s>>k>>m;

    ll fc = m/k; 
    ll rc = m%k;

    
    if(k>=s){
        if(rc >= s)
            print(0);
        else{
            print(s-rc);
        }
    }
    else{
        int ans = (fc%2 ==0 ? s : k);
        if(rc >= ans)
            print(0);
        else{
            print(ans-rc);
        }
    }

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


