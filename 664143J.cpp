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


void toh(int n, char a,char b, char c){
    if(n==0) return;

    toh(n-1, a, c, b);
    
    print("Move ", a, " to ", c);
    
    toh(n-1, b, a, c);
}


void solve(){    
    int n;cin>>n;

    toh(n,'A','B','C');

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
