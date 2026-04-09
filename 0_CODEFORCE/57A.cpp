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

int mndist(int n, int x, int y){
    
    // for     y direction 
    // if (y==0) return 3*n+(n-x);
    // if(x==n) return 2*n+(n-y);
    // if (y==n) return n+x;
    // return y;


    // for x direction
    if (y==0) return x;
    if(x==n)  return n+y;
    if (y==n) return n+n+(n-x);
    return n+n+n+(n-y);
}

bool solve(){
    int n,x1,y1,x2,y2;cin>>n>>x1>>y1>>x2>>y2;
    
    
    int p1 = abs(mndist(n, x1,y1));
    int p2 = abs(mndist(n, x2, y2));
    
    int d = abs(p1-p2);
    int final_d = min(d, abs(4*n - d));
    
    print(final_d);
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