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

    ll n,k,x;cin>>n>>k>>x;

    // max possible
    // ll mx=0ll;
    // f(i,1,k+1){
    //     mx+= n-k+i;
    // }
    /*
    sum of ap for a+...+b series
        => n*(a+b)/2
    */
    ll mx = k*((2*n-k+1))/2;


    if(x>mx or x < (k*(k+1)/2)){
        print("NO");
        return;
    }

    print("YES");

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
