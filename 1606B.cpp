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
    just doubling up and then  calculating remaining pcs...
  */
 
    ll cable,pc;cin>>pc>>cable;

    ll ans;
    if(cable==1){
        ans = (pc - 1);
    }
    else{
        ans=0;
        ll current_computer=1;

        while(current_computer < cable and current_computer < pc){
            ans++;
            current_computer<<=1ll;
        }

        if(current_computer < pc){
            // print("--> done pcs -", current_computer);
            // print("rem  - ", pc-current_computer, "   by ", cable);
            ans += ((pc-current_computer + cable -1) / cable);
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