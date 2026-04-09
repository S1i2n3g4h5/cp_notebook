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



const bool multipleTestCases = 0;


void solve(){
    int n;cin>>n;
    vector<ll> arr(n);
    f(i,0,n)cin>>arr[i];

    // find 1st pos idx
    int l=0;
    f(i,0,n){
        if(arr[i]<=0){
            continue;
        }
        l=i;
        break;
    }

    ll currsm =arr[l];
    ll mxsm=arr[l];
    f(i,l+1,n){
        currsm += arr[i];
        mxsm = max(mxsm, currsm);
        currsm = max(0LL,currsm);
    }

    if(mxsm<0){
        print(*max_element(arr.begin(), arr.end()));
    }
    else
        print(mxsm);
  
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