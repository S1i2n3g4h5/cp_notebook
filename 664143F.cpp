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

    int n,k;cin>>n>>k;
    vector<bool>present(n+1,0);
    
    f(i,0,n){
        int x;cin>>x;
        
        if(x < n) 
            present[x]=1;
    }


    // sort(arr.begin(), arr.end());

    f(i,0,n){
        if(!present[i]){
            if(k > 0) 
                k--;
            else{
                print(i);
                return;
            }
        }
    }

    
    print(n);


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
