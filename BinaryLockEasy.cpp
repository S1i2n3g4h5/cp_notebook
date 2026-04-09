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

    ll n, k;cin>>n>>k;

    // print(1LL << __builtin_popcountll(n));

    if (k==1) {
        print(0);
        return;
    }
    else if(k > (1LL << __builtin_popcountll(n))){
        print(-1);

        return;
    }
    
    

    ll ans = 0;
    ll curr =k-1;

    
    f(i,0,64){
        if((n >>i) & 1){
            if(curr & 1){
                // print(i, "  - ", curr, " - ");   
                ans= ans | (1ll << i);
                
            }
            
            curr >>= 1;
        }
    }



    if(curr <=1){
        print(ans);
        return;
    
    }

    print(-1);


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