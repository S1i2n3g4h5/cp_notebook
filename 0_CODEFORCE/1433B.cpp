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


void solve(){
    
    int n;cin>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];


    vector<int> pos1;
    f(i,0,n){
        if (arr[i]==1)pos1.push_back(i);
    }

    if (pos1.size()<=1){
        print(0);
        return;
    }

    int zeros =0;
    f(i,pos1[0],pos1[pos1.size()-1]){
        if (arr[i]==0)zeros++;
    }
    print(zeros);
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