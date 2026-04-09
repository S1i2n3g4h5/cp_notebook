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
    vector<int> a(n);
    f(i,0,n)cin>>a[i];


    int currlen = 1;
    int mxlen = 1;

    f(i,1,n){
        if( a[i-1] <= a[i])currlen++;
        else{
            currlen = 1;
        }
        mxlen = max(mxlen, currlen);

    }

    print(mxlen);


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