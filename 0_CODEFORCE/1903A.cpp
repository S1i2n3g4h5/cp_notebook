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
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    f(i,0,n)cin>>arr[i];


    bool srt=true;
    f(i,1,n){
        srt &= (arr[i-1]<=arr[i]);
    }
  

    if(!srt and k<=1)
        print("NO");
    else{
        print("YES");
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