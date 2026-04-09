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



const bool multipleTestCases = 1;


void solve(){
  int n;cin>>n;
  string s;cin>>s;


  if(s.find("AB") == string::npos){
    print(0);
    return;
  }


  vector<int> prefixA(n),suffixB(n);
  prefixA[0] = s[0]=='A';
  f(i,1,n){
    prefixA[i] += prefixA[i-1] + (s[i]=='A');
  }
  suffixB[n-1]=s[n-1]=='B';
  for(int i=n-2;i>=0;i--){
    suffixB[i] += suffixB[i+1] + (s[i] =='B');
  } 
  

  int ans=0;
  f(i,0,n-1){
    if(prefixA[i] >0 and suffixB[i+1]>0)ans++;
  }

  print(ans);
  
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