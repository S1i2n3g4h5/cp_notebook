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

  int n,x;cin>>n>>x;
  vector<int>w(n);
  f(i,0,n)cin>>w[i];

    sort(w.begin(), w.end());

    int j=n-1, i=0;
    int g=0;
    while(i<=j){
        ll curr = w[i]+w[j];

        if(i==j){
            g++;
            break;
        }

        if(curr <= x){
        
            i++;
            j--;
        }
        else{
            j--;
        }

        g++;
    }

    print(g);
    
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