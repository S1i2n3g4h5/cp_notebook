/*
  Competing against Myself  
  [zoASHro]
*/
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
  /*

  */

  int n;cin>>n;
  string s;cin>>s;


    int r0=-1,rn=-1,l0=-1,ln=-1;
    f(i,0,n){
        if(s[i] == 'R'){
            if(r0 == -1) r0=i+1;
            rn=i+1;
        }
        else if(s[i] == 'L'){
            if(l0 == -1) l0=i+1;
            ln=i+1;
        }
    }


    if(r0 == -1){
        print(ln, " ", l0 - 1);
    }
    else if(l0 == -1){
        print(r0, " ", rn + 1);
        
    }
    else{
        print(r0, " ", l0);
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
