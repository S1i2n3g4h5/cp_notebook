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
  
    ll n,k;cin>>n>>k;



    if(k>n){
        print(-1);
        return;
    }
    else if(k==n){
        print(0);
        return;
    }


    ll div=1LL;
    ll steps=0LL;

    f(i,1,33){
        div <<= 1LL;


        ll l=n/div;
        
        ll r=(n+div-1)/div; //ceil(n/div)


        if(l==k  or r==k){
            print(i);
            return;
        }
        
        if(r < k){
            break;
        }

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


