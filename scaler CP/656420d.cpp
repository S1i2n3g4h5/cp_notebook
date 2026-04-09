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

void printbinary(ll a){

    f(i,0,10){
        if (a&(1<<(9-i))){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    cout << endl;

}


bool solve(){
    

    ll a,b;cin>>a>>b;



    ll xor_ab = a^b;
    ll power =1;
    while(xor_ab){
        if ( (xor_ab & 1) ==1){
            break;
        }
        power*=2;
        xor_ab >>= 1;
    }
    print(power);
    

    
  return 1;
}

 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    while(t--){
      solve();
    }
    return 0;
}   