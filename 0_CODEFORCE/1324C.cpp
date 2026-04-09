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


void solve(){
    string s;cin>>s;
    int n = s.size();

    vector<int> pos;
    f(i,0,n){
        if (s[i]=='R')pos.push_back(i+1);
    }

    int d=pos.size()>0 ? pos[0]:-1;
    f(i,1,pos.size()){
        d=max(d, pos[i]-pos[i-1]);
    }

    print(d == -1 ? n+1 : max(d, (n+1)-pos.back()));
  
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