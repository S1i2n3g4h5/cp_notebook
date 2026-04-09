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
    for(ll i=0;i<=10;i++){
      print((ll)(pow(3,i)));
    }


    // int n;cin>>n;

    // set<int> a;
    // f(i,0,n){
    //   int tmp;cin>>tmp;
    //   a.insert(tmp);
    // }

    // int sz=a.size();
    // int mn=INT_MAX;
    // for(int ai:a){
    //   if (ai>=sz){
    //     mn=min(mn,ai);
    //   }
    // }
    // print(mn);
    
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