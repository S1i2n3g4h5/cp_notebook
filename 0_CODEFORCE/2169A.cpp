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
    int n,a;cin>>n>>a;
    vector<int> arr(n);
    int l=0,r=0;
    f(i,0,n){
        cin>>arr[i];
        if (arr[i]<a)l++;
        if(arr[i]>a)r++;
    }
  
    if(l>r){
        print(a-1);
    }
    else{
        print(a+1);

    }
    
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