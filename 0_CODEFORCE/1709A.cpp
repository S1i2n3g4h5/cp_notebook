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
    int curNum;cin>>curNum;
    map<int,int>numFreq;
    cin>>numFreq[1];
    cin>>numFreq[2];
    cin>>numFreq[3];
    
    int currDoor= curNum;
    int cnt=1;
    while(numFreq[currDoor]>0 ){
        currDoor = numFreq[currDoor];
        cnt++;
    }

    if(cnt==3)print("YES");
    else
        print("NO");    
    

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