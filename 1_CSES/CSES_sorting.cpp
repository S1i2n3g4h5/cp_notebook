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


void solve(){
    
    int n;cin>>n;
    vector<int>A(n);
    f(i,0,n)cin>>A[i];


    sort(A.begin(), A.end());

    int cnt =1;
    f(i,0,n-1){
        if (A[i] != A[i+1])cnt++;
    }

    print(cnt);
  
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