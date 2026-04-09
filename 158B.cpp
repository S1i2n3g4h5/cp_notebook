/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
 

  ll n;cin>>n;
  vector<ll>arr(n);
  f(i,0,n)cin>>arr[i];


  ll one=0,two=0,three=0,four=0;
  f(i,0,n){
    if(arr[i] == 1)one++;
    else if(arr[i] ==2)two++;
    else if(arr[i] ==3)three++;
    else four++;
  }


  ll tot = four;
  

  // three + ones
  tot += three;
  one = max(0ll, one - three);


  // two
  tot += two/2;
  if(two%2 == 1){
    tot ++;
    one = max(0ll, one - 2);
  }



  if(one > 0){
    tot += (one + 4 -1)/4;
  }

  print(tot);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}