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



const bool multipleTestCases = 1;


void solve(){    string s;
    cin >> s;
    int cnt = 0;
    if (s[0] == 'u') {
        cnt++;
        s[0] = 's';
    }
    for (int i = 1, dist = 0; i < s.size(); i ++) {
        if (s[i] == 'u') {
            dist++;
        }
        else {
            dist = 0;
        }
        if (dist > 1) {
            dist = 0;
            s[i] = 's';
            cnt++;
        }
    }

    print((s.back() == 'u' ? cnt + 1 : cnt));
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