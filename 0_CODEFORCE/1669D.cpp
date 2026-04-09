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
    
    int n;cin >> n;
    string s;cin >> s;

    if (n == 1) {
        if (s[0] == 'W') print("YES");
        else print("NO");

        return; 
    }
    
    stringstream ss(s);
    string token; 
    while (getline(ss, token, 'W')) {
        if (token.size()>0) {
            if (token.find('B') == string::npos  or token.find('R') == string::npos) {
                print("NO");
                return 1;
            }
        }
    }
    print("YES");

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