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
    int n;cin>>n;

    /*  

    watch out for worstcase senrai only
        =>   n-p-1  for all pending and removing 1 aswell cuz there ezists 1 winning press
        =>   1-p   for worst case we assume the cost adds for every wrong p

    */
    int s=0;
    f(i,0,n){
        s += ((n-i-1) * (1+i) + 1);
    }
    print(s);

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