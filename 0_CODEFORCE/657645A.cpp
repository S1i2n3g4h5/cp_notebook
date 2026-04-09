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
    int n,m;cin>>n>>m;

    map<string, string> dict;
    f(i,0,m){
        string a,b;cin>>a>>b;

        if (a.size()<= b.size())dict[b] = a;
        else dict[a]=b;
    }

    f(i,0,n){
        string curr;cin>>curr;

        if (dict.find(curr) != dict.end())
            cout << dict[curr];
        else
            cout << curr;
        cout <<" ";
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