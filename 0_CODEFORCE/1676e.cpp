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
    int n,q;cin>>n>>q;
    vector<ll> candies(n);
    f(i,0,n)cin>>candies[i];
    
    sort(candies.begin(), candies.end());
    reverse(candies.begin(), candies.end());

    vector<ll> prefix(n);
    prefix[0]=candies[0];
    f(i,1,n)prefix[i] = prefix[i-1]+candies[i];
    
    ll currquery;    
    f(i,0,q){
        cin>>currquery;
        // print("               ->", currquery);
        
        // Apply lowerbound binary search
        if (currquery > prefix[n-1])
            print(-1);
        else{
            int outidx = lower_bound(prefix.begin(), prefix.end(), currquery)-prefix.begin();
            
            print(outidx + 1);
        }

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