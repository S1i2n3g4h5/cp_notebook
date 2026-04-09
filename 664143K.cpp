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

    map<char,char>dict;
    f(i,0,26){
        char a,b;cin>>a>>b;
        dict[a]=b;
    }
    string s;cin>>s;

    
    f(i,0,s.size()){
        cout << dict[s[i]];
    }
    cout <<"\n";


  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
