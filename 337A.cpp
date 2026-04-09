/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    This is too easy jus obs
    that after sorting use a fixed k-window running through array
  */
 
    int k,n;cin>>k>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];
    sort(arr.begin(),arr.end());

    int i=k;
    int ans=INT_MAX;
    while(i<=n){

        int mx = *max_element(arr.begin()+(i-k), arr.begin()+i);
        int mn = *min_element(arr.begin()+(i-k), arr.begin()+i);


        ans = min(ans, mx - mn);
        i++;
    }

    print(ans);

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