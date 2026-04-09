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
    
    // int n;cin>>n;
    // vector<int> a(n);
    // f(i,0,n)cin>>a[i];
    // vector<int> even,odd;
    // f(i,0,n){
    //     if (a[i]%2==0)even.push_back(a[i]);
    //     else odd.push_back(a[i]);
    // }

    // if (even.size() == 0 or odd.size() == 0){
    //     f(i,0,n){
    //         cout << a[i] << " ";
    //     }
    //     return 1;
    // }

    // sort(a.begin(), a.end(), [](const int a1,const int a2){
    //     return a1<a2;
    //     });
       

    // f(i,0,n){
    //     cout << a[i] << " ";
    // }




  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   