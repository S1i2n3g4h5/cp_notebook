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
int smR(string n){
   if(n.size() == 1)
        return 0;
   
   ll sum = 0;
   for(char& s:n)
        sum += (s-'0');
   

   return smR(to_string(sum))+1;
}

bool solve(){
    string s;cin>>s;
    
    print(smR(s));

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