/*
  Competing against Myself  
  [zoASHro]
*/
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
 
    int n;cin>>n;
    string s;cin>>s;

    
    int balance=0;
    int valid=0;
    bool last_invalid =0;
    f(i,0,n){
        if(s[i] == '('){
            balance += 1; 
            // last_invalid=0;
        }
        else{
            balance += -1;
            // last_invalid=0;
        } 
            
        if(balance ==0 and !last_invalid)
            valid++;
            last_invalid=0;
        
        // disbalance
        if(balance < 0){
            last_invalid=1;
            balance=0;
        }
    }

    // print(valid, " ", balance);
    print(balance);

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