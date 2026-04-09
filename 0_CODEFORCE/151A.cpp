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
    
    int n,k,l,c,d,p,nl,np;cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    if((k*l) / nl < n){
        print(0);
        return;
    }
    if((c*d) <n){
        print(0);
        return;
    }
    if((p/np) < n){
        print(0);
        return;
    }

    print(min((k*l)/nl, min(c*d,p/np) ) / n);

  
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