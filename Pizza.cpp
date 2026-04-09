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

int n;
vector<int> a;
int dp[105][105][105];

int solve_dp(int i, int j, int k) {
    if (i > j) return 0;
    
    while (i + 1 <= j && a[i] == a[i+1]) {
        i++;
        k++;
    }

    if (dp[i][j][k] != -1) return dp[i][j][k];

    int res = (k + 1) * (k + 1) + solve_dp(i + 1, j, 0);
    // Option 2: Try to merge with next occurrence of the same topping
    for (int m = i + 1; m <= j; m++) {
        if (a[m] == a[i]) {
            // If we merge a[i] with a[m], we must clear everything in between (i+1 to m-1)
            // The k carries over to m, plus the 1 from a[i] itself (which is now effectively attached to m)
            res = max(res, solve_dp(i + 1, m - 1, 0) + solve_dp(m, j, k + 1));
        }
    }

    return dp[i][j][k] = res;
}

void solve(){    
    cin >> n;
    a.resize(n);
    f(i, 0, n) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    /*
    // int ans = 0;
    // f(i,0,n) ans += 1; // greedy fails
    // print(ans);
    // 
    // // dp[i][j] = max(dp[i+1][j] + 1, ...); // Missing k parameter, need to track attached count
    */

    print(solve_dp(0, n - 1, 0));
  
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