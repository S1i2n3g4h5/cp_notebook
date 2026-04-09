#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 1; 


void solve(){
  /*
    
  */
 
    int n;
    string s;
    cin>>n>>s;


    int ans=0;
    f(i,0,n){
        if(s[i]=='0')
            ans++;
        else{
            ans += n-1;
        }
    }


    print(ans);


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}