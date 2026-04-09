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


void solve() {
    
  /*
  Phoenix has n blocks of height h1,h2,…,hn, and all hi don't exceed some value x. He plans to stack all n blocks into m separate towers. The height of a tower is simply the sum of the heights of its blocks. For the towers to look beautiful, no two towers may have a height difference of strictly more than x
Please help Phoenix build m
towers that look beautiful. Each tower must have at least one block and all blocks must be used.

    print yes if its possible and print the index of tower for ith block si placed into else print no
*/

    int n,l,r;cin>>n>>l>>r; 
    
    vector<int> h(n);
    f(i,0,n) cin>>h[i];
    
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    
    f(i,1,l+1){
        pq.push({0,i});
    }
    
    vector<int> ans(n);
    
    f(i,0,n){
        auto top = pq.top();
        pq.pop();
        ans[i]=top.second;
        top.first+=h[i];
        pq.push(top);
    }
    
    print("YES");
    f(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    
  
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