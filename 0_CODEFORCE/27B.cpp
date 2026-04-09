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

  vector<int>wins(n+1,0),loss(n+1,0);
  int total = n*(n-1)/2-1;
  f(i,0,total){
    int x,y;cin>>x>>y;
    wins[x]++;
    loss[y]++;
  }

  int x=-1,y;
  f(i,0,n+1){
    if (wins[i] + loss[i] == n-2){
      if (x==-1)x=i;
      else y=i;
    }
  }

  if (wins[x]<wins[y])
    print(y, " ", x);
  else{
    print(x, " ", y);

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