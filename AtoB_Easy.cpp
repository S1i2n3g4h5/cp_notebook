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
typedef long long ll;

const bool multipleTestCases = 1; 

void solve(){
    int n;
    if(!(cin >> n)) return;
    string a, b;
    cin >> a >> b;

    if (a == b) {
        print(0);
        return;
    }

    // If both ends need flipping and are currently different, cost is 0
    if (a[0] != b[0] && a[n-1] != b[n-1] && a[0] != a[n-1]) {
        print(0);
    } else {
        // Otherwise, at least one cost-1 operation is required
        print(1);
    }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--) solve();
  return 0;
}