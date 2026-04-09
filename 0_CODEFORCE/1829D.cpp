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

bool find_ans(int n,int m){
    if (n==m)
        return true;
    else if(n%3 >0)
        return false;

    else 
        return find_ans(n/3,m) or find_ans(2*n/3, m);
}

void solve(){
    int n,m;cin>>n>>m;
    
    if(find_ans(n,m)){
        print("YES");
    }
    else{
        print("NO");
    }
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