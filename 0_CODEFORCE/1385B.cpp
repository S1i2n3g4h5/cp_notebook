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


void solve(){
    int n;cin>>n;
    vector<int> arr(2*n+1,0);
    vector<bool> found(n+1,false);
    found[0]=1;
    f(i,0,n*2){
        cin>>arr[i];
        if (!found[arr[i]]){
            cout << arr[i] << " ";
            found[arr[i]] = 1;
        }
    }
  cout << endl;
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