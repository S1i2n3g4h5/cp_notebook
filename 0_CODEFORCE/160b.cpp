#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}
#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


const bool multipleTestCases = false;

bool solve(){

    int n;cin>>n;
    string s;cin>>s;
    
    sort(s.begin(), s.begin()+n);
    sort(s.begin()+n, s.end());

    vector<bool> check(n);
    bool up=true;
    bool down=true;
    

    for(int i=0;i<n;i++){
        int a = (int)(s[i] - '0');
        int b = (int)(s[n+i]- '0');

        up = up and a>b;
        down = down and a<b;
        
    }
    

    if (up or down )
        print("YES");
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