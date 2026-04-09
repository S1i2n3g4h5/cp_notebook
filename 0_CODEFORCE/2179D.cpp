#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args) {
    ((std::cout << args << (sizeof...(args) > 1 ? " " : "")), ...);
    std::cout << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double

const bool multipleTestCases = true;

void solve(){
    int n;cin>>n;


    vector<bool> used((1 << n),0);

    
    for(int i=n;i>=0; i--){
        int val = (1<<i)-1;
        if (used[val]==false) {
            cout<< val<<" ";
            used[val]=1;
        }
    }


    f(i,0,(1<<n)){
        if (!used[i]) {
            cout <<i<< " ";
  
            used[i] = true;
      
        }
    }


    cout << "\n";

    return;
}

int main() {
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