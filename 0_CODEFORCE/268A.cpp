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
    int n;cin>>n;
    vector<pair<int,int>> arr;
    arr.reserve(n);
    map<int,int> freq;
    f(i,0,n){
        pair<int,int> curr;
        cin>>curr.first >> curr.second;
        arr.push_back(curr);

        freq[curr.second]++;
    }
    
    int cnts=0;
    f(i,0,n){
        cnts +=freq[arr[i].first];
    }
    print(cnts);
  
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