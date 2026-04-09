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



const bool multipleTestCases = 1;


void solve(){
    int n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    if(n==1){
        print(0);
        return;
    }

    vector<ll>cp_arr = arr;
    sort(cp_arr.begin(), cp_arr.end());
    
    // storing indexes which later will be used to fix ordering of elems
    vector<int>indexes(n);
    f(i,0,n){
        indexes[i] = arr[i];
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