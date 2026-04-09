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
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n){
        cin>>arr[i];    
    }

    int first_parity = -1;
    bool ys=1;
    bool all_same = true;
    
    
    f(i,0,n) {
        int current_parity = (i + arr[i]) % 2; 
        
        if (i==0){
            first_parity = current_parity;
        } 
        else{
            if (current_parity != first_parity) {
                ys = 0;
            }
        }
    }

    if (ys) print("YES");
    else print("NO");
    
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
