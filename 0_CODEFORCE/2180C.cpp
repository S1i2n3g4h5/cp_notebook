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


string print_binary(ll a, int mx=10){
    string s;
    for(int i=mx;i>=0;i--){
        s+=to_string(((a>>i)&1));
    }
    return s;

}

int build_binary(int i){
    // building binary based on given set bit
    return (1<<i);
}

const bool multipleTestCases = true;

bool solve(){
    
    int n,k;cin>>n>>k;

    // for(int i=0;i<32;i++){

    //     bool isset = ((n>>i) & 1) == 1;
    //     if(isset){
    //         int bs = build_binary(i);
    //         out = (out | bs);
    //         // print("building  - ", bs, " ", print_binary(bs,5));
    //         print(out, "  ", print_binary(out,5) );
    //     }
    //     else{
    //         continue;
    //     }

    // }

    if(k==1){
        print(n);
        return 1;
    }
    else if(k == 2){
        print(0, " ", n);
        return 1;
    }
    else if (k%2 == 1){
        f(i,0,k){
            cout << n << " ";
        }
    }
    else{
        cout <<"0 ";
        f(i,1,k){
            cout << n <<" ";
        }
    }
    cout << endl;

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