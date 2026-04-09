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




bool solve(){
    
    ll n;cin>>n;
    string out="codeforces";

    vector<int> cnts(10,1);
    ll curr = 1LL;
    
    while(curr < n){
        f(i,0,10){
            if (curr>=n) break;

            curr /= cnts[i];
            cnts[i]++;
            curr*=cnts[i];
        }

    }
    
    
    f(i,0,10){
        while(cnts[i]--){
            cout << out[i];
        }
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