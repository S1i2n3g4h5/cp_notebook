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

    // int n;cin>>n;
    // vector<int>a(2*n);
    // f(i,0,n)cin>>a[i];

    // if (n==1){
    //     print("YES");
    //     return 1;
    // }

    // f(i,0,n)a[n+i]=a[i]; // copy the rotation

    // vector<int>diff(2*n,0);
    // f(i,1,2*n){
    //     diff[i] = a[i]-a[i-1];
    //     // cout << a[i] << " ,";
    // }

    // int freq=1;
    // int chr = diff[1];
    // f(i,1,2*n){
    //     freq+=(diff[i] == chr);
    //     // cout << chr <<" ,";
    //     if (freq == n-1){
    //         print("YES");
    //         return 0;
    //     }
    //     if (diff[i]!=chr){
    //         chr = diff[i];
    //         freq=1;
    //     }

    // }
    // print("NO");



    
    /*
        editorial solution reimplementing ...
    */

    int n;cin>>n;
    vector<int> a(n);
    int p;

    f(i,0,n){
        cin>>a[i];
        if (a[i] == 1)p=i;
    }

    bool left = 1, right=1;
    f(i,1,n){
        left &= (a[(p-i+ n)%n] == i+1);
        right &= (a[(p+i + n)%n] == i+1);
    }

    cout << (left or right ? "YES\n":"NO\n");
  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   