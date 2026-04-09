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
    int l,a,b;cin>>l>>a>>b;

    vector<bool>vst(l,0);
    int ans=a;
    while (!vst[a]) {
        vst[a]=true;
        ans=max(ans, a);
        a=(a+b)%l;
    }

    
    print(ans);

  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   