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
    string s;cin>>s;

    int right = count(s.begin(), s.end(), '>');
    int left = count(s.begin(), s.end(), '<');

    f(i,1,s.size()){
        if (s[i-1] != '<' and s[i]!='>'){
            print(-1);
            return 1;
        }
    }

    print(s.size()-min(right,left));

  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   