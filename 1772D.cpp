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



const bool multipleTestCases = 1;


void solve(){
  int n;cin>>n;
  vector<int> arr(n);
  bool already_sorted = true;
  f(i,0,n){
    cin>>arr[i];
    if(i>=1)
        already_sorted &= arr[i-1]<=arr[i];
    }   

    
    if(already_sorted){
        print(0);
        return;
    }

    print("...");

  
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


