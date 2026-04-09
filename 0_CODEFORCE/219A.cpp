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
    int k;cin>>k;
    string s;cin>>s;
    int n=s.size();
    
    if (k==1){
        sort(s.begin(),s.end());
        print(s);
        return 1;
    }

    // Check 0: The total length must be divisible by k
    if (n%k>0) {
        print("-1");
        return 1;
    }

    
    map<char,int>freq; 
    for (char&c:s) {
        freq[c]++;
    }
    string base;
    for(auto&p:freq){
        if (p.second%k >0){
            print(-1);
            return 1;
        }        
        // base.push_back(p.first);
        base.append(p.second/k, p.first);
    }

    f(i,0,k)cout<<base;

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