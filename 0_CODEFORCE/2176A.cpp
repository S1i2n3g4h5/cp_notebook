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



const bool multipleTestCases = true;

bool solve(){



    int n;cin>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];

    int cnt=0;
    for(int i=n-2;i>=0;i--){
        if (arr[i]>arr[i+1])cnt++;
    }
  
        print(cnt);
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