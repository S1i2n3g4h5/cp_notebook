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
    
    ll n;cin>>n;
    vector<ll> arr(n);
    f(i,0,n)cin>>arr[i];

    
    vector<ll> a(n+1,0);
    f(i,0,n){
        ll diff = arr[i+1]-arr[i];
        if (diff<0){
            a.push_back(i+1);
        }
        else{
            a.push_back(a[i-diff]);
        }
    }
    
    f(i,0,a.size()){
        cout << a[i] << " ";
    }
    cout << "\n";

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