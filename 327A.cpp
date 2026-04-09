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
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];

    // int mxcnt=0;
    // f(i,0,n){

    //     f(j,i,n){
    //         int cnt=0;

    //         f(k,0,n){
    //             if(i<=k and k<=j){
    //                 cnt += 1-arr[k];
    //             }
    //             else{
    //                 cnt += arr[k];
    //             }
    //         }

    //         mxcnt = max(mxcnt, cnt);

    //     }
    // }

    // print(mxcnt);


    // ----------------------------------------
    // O(n2) approach

    int cnt=0;
    vector<int> b(n);
    f(i,0,n){
        if(arr[i] == 1)cnt++;
        
        if(arr[i] == 1)b[i]=-1;
        else b[i]=1;
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
