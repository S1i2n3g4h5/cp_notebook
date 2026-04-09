/*
  Competing against Myself  
  [zoASHro]
*/
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define all(x)              (x).begin(), (x).end()
typedef long long ll;

const bool multipleTestCases = 1; 

void solve(){
    int n, k;
    if(!(cin >> n >> k)) return;

    vector<int> a(n);
    f(i, 0, n) cin >> a[i];

    // Sort descending to assign the K cheapest costs to the most expensive items
    sort(a.rbegin(), a.rend());

    ll total_profit = 0;
    f(i, 0, n) {
        if (i < k) {
            // First K items cost 5 each
            if (a[i] > 5) total_profit += (a[i] - 5);
        } else {
            // Remaining items cost 10 each
            if (a[i] > 10) total_profit += (a[i] - 10);
        }
    }
    print(total_profit);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--) solve();
  return 0;
}