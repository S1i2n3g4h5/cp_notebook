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

    // int n;cin>>n;

    // print(min(1000, 200*n));

    int n=432;

    vector<int> ans ;
    for (int i = 2 ; i <= n ; i++){
        while (n % i == 0 && n > 0 ){
            ans.push_back(i);
            n = n / i ;
        }
    }


    f(i,0,ans.size())cout << ans[i] <<" ";
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