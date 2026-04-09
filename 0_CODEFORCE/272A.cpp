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
  vector<int>arr(n);
  f(i,0,n)cin>>arr[i];

    int tot=accumulate(arr.begin(), arr.end(),0);
    int total_friends=0;
    f(i,1,6){
        if((tot+i)%(n+1) != 1)total_friends++;
    }

    print(total_friends);

  
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