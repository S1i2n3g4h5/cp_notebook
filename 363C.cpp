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
    here 2 rules to follow-
        + no triplets allowed                                           -> "Three identical letters together is a typo."
        + and for some patterns -> "A couple... followed by another couple... is a typo"
    
    like wwaabb   its final out is  wwab   
    
    for 1st the condition is easy. but for 2nd condition we can just check if last char is distinct there and last 2 chars from that last posisiont is same 
    
  */
 
    string s;cin>>s;

    string ans="";

    for(auto c:s){
        int n=ans.size();

        if(n >= 2 and ans[n-2] == c and ans.back() == c){
            continue;
        }

        if(n >=3 and ans.back() == c and ans[n-2] == ans[n-3])
            continue;


        ans += c;

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