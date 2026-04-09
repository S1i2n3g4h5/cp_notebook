#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 0;

void solve(){

    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;

    // // Check -1
    // if((x1 >0 and y1>0 and x1!=y1) or (x2>0 and y2>0 and x2!=y2)){
    //     print(-1);
    //     return;
    // }

    int side;
    if(x1==x2){
        side=abs(y1-y2);
        print(x1+side, " ", y1, " ", x2+side, " ",y2);
    }
    else if(y1==y2){
        side=abs(x1-x2);
        print(x1, " ", y1+side, " ", x2, " ",y2+side);
    }
    else if(abs(x1-x2) == abs(y1-y2)){
        side = abs(x1-x2);
        print(x1, " ", y2, " ",x2, " ",y1);
    }
    else{
        print(-1);
    }

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
