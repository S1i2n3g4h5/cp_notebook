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
    int n;cin>>n;

    if(n==1){
        print(1);
    }
    else if(n<=3){
        print("NO SOLUTION");
    }
    else if(n==4){
        print("3 1 4 2");
    }
    else{
        
        for(int i=n;(n&1 ? i>=1: i>1);i-=2){
            cout << i<<" ";
        }
        for(int i=n-1;((n-1)&1 ? i>=1: i>1);i-=2){
            cout << i<<" ";
        }

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
