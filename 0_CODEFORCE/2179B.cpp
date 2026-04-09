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
    vector<int>arr(n);
    int mxdiffs = 0;
    f(i,0,n)cin>>arr[i];    
    

    ll total = 0;
    ll bestSave = 0;
    f(i,1,n){
        total += abs(arr[i] - arr[i-1]);
    }


    bestSave =max(bestSave, (ll)abs(arr[1] - arr[0]));
    bestSave =max(bestSave, (ll)abs(arr[n-1] - arr[n-2]));

    f(i,1,n-1){
        ll save = abs(arr[i-1]-arr[i]) + abs(arr[i]-arr[i+1]) -
            abs(arr[i-1]-arr[i+1]);
        bestSave = max(bestSave, save);
    }

    print(total - bestSave);
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