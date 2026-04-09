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
    Since i <= A[i], the movement is always to the right or standing.
    There are no cycles other than self-loops (A[i] == i).
         compute the destination fr cell iterating backwards from N to 1.
    
        if A[i] == i, then dest[i] = i.
    iif A[i] > i, then dest[i] = dest[A[i]].
  */
 
    int n; cin>>n;
    vector<int>a(n+1);
    f(i,1,n+1) cin>>a[i];

    vector<int> ans(n+1);
    for(int i=n; i>=1;i--) {
        if (a[i] == i)
            ans[i] = i;
        else 
            ans[i] = ans[a[i]];   
    }

    
    f(i,1,n+1){
        cout << ans[i] << " ";
    }
    cout << "\n";


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