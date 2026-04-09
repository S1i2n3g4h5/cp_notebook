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
    int n,m;cin>>n>>m;
    vector<string> arr(n);
    f(i,0,n) cin>>arr[i];

    int bestcost=INT_MAX;

    f(i,0,n){
        f(j,i+1,n){

            // calculating cost ...
            string w1=arr[i];
            string w2=arr[j];
            int cost=0;
            f(k,0,m) cost += abs(w1[k] - w2[k]);
            
            bestcost = min(bestcost, cost);
        }
    }

    print(bestcost);
  
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