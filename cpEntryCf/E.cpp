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

    string x,y;cin >> x >> y;
    int n,m;
    n=x.size();
    m=y.size();
    // print(x, ",", y);
    // print(n, ",", m);


    int pos = -1;
    for(int i=m-1;i>=0;i--){
        if(y[i] == '1'){
            pos = i;
        
            break;
        
        }
    }

    // print(pos);

    int ans = 0;
    for(int i=n-m + pos;i>=0;i--){

        if (x[i] == '0') ans++;
        else 
            break;
    }


    print(ans);

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