#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 1; 


void solve(){
  /*
    
  */
 
    ll n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    if(accumulate(arr.begin(), arr.end(),0ll) == n){
        print("YES");
        return;
    }


    f(i,0,n-1){
        if(arr[i] == 0 and arr[i+1]==0){
            print("YES");
            return;
        }
    }


    print("NO");


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}