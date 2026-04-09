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
    int n,q;cin>>n>>q;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];

    vector<ll> right(n+2,0LL);
    f(i,2,n+1){
        right[i] = right[i-1] + (max(0LL, arr[i-2] - arr[i-1]));
    }
    vector<ll> left(n+2,0LL);
    for(int i=n-1;i>=1;i--){
        left[i] = left[i+1] + max(0LL, arr[i] - arr[i-1]);
    }
  
    f(i,0,q){
        int l,r;cin>>l>>r;

        if (l<r){
            print(right[r] - right[l]);
        }
        else{
            print(left[r] - left[l]);
            // print("---");
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