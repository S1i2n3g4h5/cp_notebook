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
        wow , so we dont need more than 1 step to get to answers
        as increasing one decreases other too and in a,b stirngs the combinatino is likely les slike
        like there cant be 3 ab and 1 ba     cuz    |AB(s) - BA(s)| <= 1
  */
 
    string s;cin>>s;

    int n= s.size();

    int ab=0,ba=0;
    f(i,0,n-1){
        if(s[i]=='a' and s[i+1]=='b')ab++;
        else if(s[i]=='b' and s[i+1]=='a')ba++;
    }


    if(ab != ba){
    
        if(s[0] != s[n-1]){

            s[n-1] = (s[n-1] == 'a' ? 'b' : 'a');
        }
        
    }
    print(s);

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