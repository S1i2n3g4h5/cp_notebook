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



bool solve(){

    int n,m; cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));

    f(i,0,n){
        f(j,0,m){
            
            if(i==n-1  and  j==m-1)
                arr[i][j] ='W';

            else
                arr[i][j]='B';
        }
    }

    f(i,0,n){
        f(j,0,m)cout<< arr[i][j];
        cout <<endl;
    }

    return 1;
}

 
int main() {
  ios::sync_with_stdio(0);


  cin.tie(0);
  
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    
    while(t--){
  
  
      solve();
  
    }
  
    return 0;
}   