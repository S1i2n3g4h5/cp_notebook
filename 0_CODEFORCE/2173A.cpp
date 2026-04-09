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
    int n,k;cin>>n>>k;
    string s;cin>>s;

    int score = 0;
    int awake_until = -1;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            awake_until = max(awake_until, i + k);
        } 
        else {
            if(i > awake_until) 
                score++;
        }
    }

    print(score);
  
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