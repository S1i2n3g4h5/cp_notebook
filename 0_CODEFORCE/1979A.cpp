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

    int curr = max(arr[0], arr[1]);
    int mxmin = curr;
    
    f(i,0,n){
        curr = arr[i];
        f(j,i+1,n){
            curr = max(curr, arr[j]);
            mxmin = min(mxmin, curr);
        }
    }
    
    print(mxmin-1);

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