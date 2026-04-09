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



const bool multipleTestCases = 0;


void solve(){    
    
    int n, q;cin>>n>>q;
    vector<int>a(n);
    f(i, 0, n)cin>>a[i];


    sort(a.begin(), a.end());

    while(q--){
        int x;cin>>x;

        
        // int cnt = 0;
        // f(i,0,n){
        //     if(a[i] >= x) cnt++;
        // }
        
        
        auto it = lower_bound(a.begin(), a.end(), x);
        
        // print(it - a.begin()); 
        
        print(a.end() - it);
    }
  
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