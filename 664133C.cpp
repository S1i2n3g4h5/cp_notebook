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
    string s,t;cin>>s>>t;

    
    int ans = 0;

    
    // f(i,0,n) {
    //    if (s[i] != t[i]) {
    //        ans++;

    //    }
    // }
        
    int flips=0;

    for(int i=n-1;i>=0;i--){
        // print("-------------");
        // print(s[i], " ", t[i]);
        // print(flips, "= ", flips%2, "  = ", ans);
        if (((s[i]!=t[i])  !=  (flips &1))){
            ans++;
            flips++;

        }

    }
    

    print(ans);
  
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
