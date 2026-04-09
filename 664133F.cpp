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


ll f_of_x(int i){
    ll sm= 0ll;


    for(int j=1;j*j<=i;j++){

        if(i%j==0){
            // print("----------------");
            // print(j, ",",i, "  ", sm);
            sm += (j%2==0 ? 1:-1);
            
            if(i != j*j){

                sm += ((i/j)%2 == 0 ? 1 : -1);
            } 
        
        }
    }

    return sm;
}


void solve(){    

    int n;cin>>n;


    ll cnt=0;
    // f(i,1,n+1){

    //     // if(f_of_x(i) == 0){
    //     //     // print("found -. ", i);

    //     //     cnt++;
    //     // }
    // }


    // print(cnt);
    print((n+2)/4);


    
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
