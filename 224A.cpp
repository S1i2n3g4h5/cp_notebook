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

  ll a,b,c;cin>>a>>b>>c;


    ld s1 = sqrt(a*b/c);
    ld s2 = sqrt(b*c/a);
    ld s3 = sqrt(c*a/b);
    
    
    print(4*(s1 + s2 + s3));

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
