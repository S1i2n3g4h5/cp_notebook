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



const bool multipleTestCases = false;


bool solve(){

  int A=99;


  int bit = (int) log2(A) + 1;
  int x = 0;
  
  // x is equal to the summation of unset bits in A
  for (int i = 0; i < bit; i++) {
      if (A & (1 << i)) 
          continue;
      x += (1 << i);
  }
  // y equals the power of 2 just greater than A
  int y = (1 << bit);

  print(x," ", y);

  int ans = (x ^ y);
  
  print(ans);


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