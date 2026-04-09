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
    
    int n;cin>>n;
    bool a[3005] = {false};
    a[0]=true;
    f(i,0,n){
        int t;cin>>t;
        a[t]=true;
    }

    f(i,1,3005){
        if (a[i] == false){
            print(i);
            return;
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