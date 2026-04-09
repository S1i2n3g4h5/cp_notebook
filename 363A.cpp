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
 
    map<int,string> draw = {{0,"O-|-OOOO"},
                            {1,"O-|O-OOO"},
                            {2,"O-|OO-OO"},
                            {3,"O-|OOO-O"},
                            {4,"O-|OOOO-"},
                            {5,"-O|-OOOO"},
                            {6,"-O|O-OOO"},
                            {7,"-O|OO-OO"},
                            {8,"-O|OOO-O"},
                            {9,"-O|OOOO-"}};  

    int n;cin>>n;
    if(n==0){
        print(draw[0]);
        return;
    }
    while(n){
        int d=n%10;


        print(draw[d]);

        n=n/10;

    }

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