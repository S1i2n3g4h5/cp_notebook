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
    int n, k;
    if(!(cin >> n >> k)) return;

    vector<int> b(n);
    vector<int> ones;
    f(i, 0, n) {
        cin >> b[i];
        if (b[i] == 1) {
            ones.push_back(i + 1); // Store 1-based positions
        }
    }

    // If S is empty, the first element of any permutation (P1) 
    // would have been added to S. Thus S cannot be empty for N >= 1.
    if (ones.empty()) {
        print("No");
        return;
    }

    // 1. Internal Consistency: Any two elements in S must be > K apart.
    f(i, 0, (int)ones.size() - 1) {
        if (ones[i+1] - ones[i] <= k) {
            print("No");
            return;
        }
    }

    // 2. External Coverage: Every number must be within distance K of a '1'.
    // Check boundaries
    if (ones[0] - 1 > k || n - ones.back() > k) {
        print("No");
        return;
    }
    // Check gaps between consecutive ones
    f(i, 0, (int)ones.size() - 1) {
        if (ones[i+1] - ones[i] > 2 * k + 1) {
            print("No");
            return;
        }
    }

    print("Yes");
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--) solve();
  return 0;
}