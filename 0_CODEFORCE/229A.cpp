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

    int n,m;cin>>n>>m;
    vector<string>arr(n);
    bool all_zero=false;
    f(i,0,n){
        cin>>arr[i];
        arr[i]+=arr[i];  // adding cyclic shift order
        if (arr[i] == string('0',m)){
            all_zero=true;
        }
    }

    if (all_zero){
        print(-1);
        return 1;
    }


    // Solution exists....
    int out = 0;

    

    
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