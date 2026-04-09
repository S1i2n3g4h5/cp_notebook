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
    string a, b;cin>>a>>b;
    int n=a.size(), m=b.size();


    /*
    Greedy: Look for the longest B-substring starting from substr then at last checking single char means starting with biggest substring available then reducing until its not found.
    
    Move forward: next search in A must start after this segment ends

    */

    int i=0,j=0,ans=0;

    while(i<m){
        int mx=0;

        for(int l=m-i;l;--l){
            auto x=a.find(b.substr(i,l),j);
        
            if(x != string::npos){
                mx = l;
                j = x+l;
        
                break;
        
            }
        }

        ans++;
        i+=mx;
    }

    
    print(ans);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    if (multipleTestCases) cin >> t;    
    while(t--){  
        solve();
    }  
    return 0;
}