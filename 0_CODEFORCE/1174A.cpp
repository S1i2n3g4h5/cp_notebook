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
    vector<int> arr(n*2);

    f(i,0,2*n)cin>>arr[i];


    sort(arr.begin(), arr.end());

    
    if (arr[0] == arr.back()){
        print(-1);
        return 1;
    }

    
    f(i,0,2*n){
        cout << arr[i] << " ";
    }
    
  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   