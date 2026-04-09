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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int ans = 0;
    int flips = 0;

    // Greedy from right to left
    for(int i = n - 1; i >= 0; i--) {
        int val = (s[i] - '0') ^ (t[i] - '0');
        
        // If current position is different from target after accounting for previous flips
        if ((val ^ (flips % 2)) == 1) {
            ans++;
            flips++;
        }
    }
    
    /*
    // Try from left to right?
    // f(i, 0, n) {
    //    if (s[i] != t[i]) {
    //        ans++;
    //        // flip prefix i+1
    //        // but this changes s[0..i] which we already fixed?
    //        // no, this doesn't work easily.
    //    }
    // }
    */

    print(ans);
  
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