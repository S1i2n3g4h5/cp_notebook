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
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];
  

    /*
    choosing 2 mx elems
    */
    ll mx1=arr[0], mx2=arr[1];
    f(i,1,n){
        if (arr[i] > mx1){
            mx2 = mx1;
            mx1 = arr[i];
        }
        else if (arr[i] >= mx2 ){
            mx2 = arr[i];
        }
    }

    print(mx1 + mx2);

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