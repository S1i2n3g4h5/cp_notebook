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
 
    go reverse from 0 to building that number;
  */
 
    ll a,b;cin>>a>>b;

    if(!a){
        print(0);
        return;
    }

    ll ans=a+1;
    
    f(i,b<2?2-b : 0, ans){
        ll A= a;
        ll B = b+i;
        ll tmp_res = i;
        while(A){
            A/=B;
            tmp_res++;
        }

        ans=min(ans,tmp_res);

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