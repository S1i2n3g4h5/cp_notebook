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

const bool multipleTestCases = true;



bool solve(){
    string s ;cin>>s;

    // scanning for consecutive chars
    if (s.find("aa") != string::npos  or s.find("bb") != string::npos  or s.find("cc") != string::npos){
        print(-1);
        return 1;
    }

    f(i,0,s.size()){
        if (s[i] == '?'){

            for(char c:{'a','b','c'}){
            
                if ((i==0  or s[i-1]!=c) and ((i+1)==s.size()  or  s[i+1]!=c))
                        s[i] = c;
            }
        }

    }


    print(s);

    return 1;
}

 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    while(t--){
      solve();
    }
    return 0;
}   