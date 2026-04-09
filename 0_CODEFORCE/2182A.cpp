#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args) {
    (cout << ... << args) << "\n";
}

#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long

const bool multipleTestCases = 1;

void solve(){
    int n;string s;cin>>n>>s;


    if(s.find("2026") != string::npos  or s.find("2025") == string::npos){
        print(0);
        return;
    }

    
    print(1);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1; multipleTestCases and cin >> t;    
    while(t--){  
        solve();
    }  
    return 0;
}
