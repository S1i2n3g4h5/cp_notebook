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
    ll n;cin>>n;

    vector<ll> q(n-1);
    ll mn=0LL,sm=0LL;
    f(i,0,n-1){
        cin>>q[i];
        sm+=q[i];
        mn = min(mn, sm);
    }
    // print(mn);
    vector<bool> visited(n+1);
    vector<ll> p(n);
    p[0]= 1-mn;
    if (p[0] >= 1 and p[0] <=n)
        visited[p[0]]=1;
    bool prnt=true;
    f(i,1,n){
        p[i]=p[i-1]+q[i-1];
        if( p[i] <= n)
            visited[p[i]] = 1;
    }

    f(i,1,n+1){
        if(!visited[i]){
            print(-1);
            return 1;
        }
    }

    f(i,0,n)cout << p[i] << " ";
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