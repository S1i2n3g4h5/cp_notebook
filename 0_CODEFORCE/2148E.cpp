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
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    map<int, vector<int>> positions;
    f(i,0,n)cin>>arr[i],positions[arr[i]].push_back(i);

    // map<int,int> max_outside;
    for(auto& [val,idx] : positions){
        if (idx.size()%k !=0){
            print(0);
            return 1;
        }
        // max_outside[val] = idx.size()/k;
    }  
  
    int minr=-1;
    for(auto& [val, idx]:positions){
        int tot=idx.size();
        int quote=idx.size()/k;
        minr = max(minr, idx[tot - quote -1]);
    } 

    ll ans=0;
    map<int, int> droped_left;
    f(i,0,n){

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