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
    int x, y, z;
    if(!(cin >> x >> y >> z)) return;

    int pass_count = 0;
    if (x >= 50) pass_count++;
    if (y >= 50) pass_count++;
    if (z >= 50) pass_count++;

    if (pass_count >= 2) print("PASS");
    else print("FAIL");
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}