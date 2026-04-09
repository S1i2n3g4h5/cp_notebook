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

int iceil(int a,int b){
    return (a+b-1)/b;
}

void solve(){       

    int n,x;cin>>n>>x;
    vector<int>arr(n);
    bool all_small=1;

    f(i,0,n){
        cin>>arr[i];

    }


    int mx=0;
    int idx=0;
    f(i,0,n){
        if(iceil(arr[i],x) >= mx){
            mx = iceil(arr[i],x);
            idx = i+1;
        }
    }
    print(idx);


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
