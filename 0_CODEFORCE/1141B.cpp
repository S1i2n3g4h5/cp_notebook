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
    int n;cin>>n;
    string s;
    s.reserve(2*n);
    f(i,0,n){
        char c;cin>>c;
        s.push_back(c);
    }
    s+=s;

    int max_so_far = 0; 
    int max_ending_here = 0; 

    for (int i=0;i<2*n;i++) {
        max_ending_here = max_ending_here + (s[i]=='1');

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        
        if (s[i] == '0') {
            max_ending_here = 0;
        }
    }
    print(max_so_far);

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