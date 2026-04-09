#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
 
    int n;cin>>n;
    int _100=0,_200=0;
    f(i,0,n){
        int x;cin>>x;
        if(x==100)
            _100++;
        else
            _200++;
    }

    ll sm = _100*100 + 200*_200;
    if(sm%200 != 0 or (_100==0 and _200%2!=0)){
        print("NO");
        return;
    }

    print("YES");

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