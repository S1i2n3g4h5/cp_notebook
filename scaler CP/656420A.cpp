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

    int n;cin>> n;


    ll total =0;

    f(i,0,n){
        ll a;cin>> a;
        total+=a;
    }


    ll root = (long long)sqrt(total);

    if (root*root == total){

        print("YES");
    }
    else{
        print("NO");
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