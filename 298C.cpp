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
    parity-> (cnt_one is odd ) ?  1  : 0;

    addition only possible for end
    removing from first

    <similar to queue operations>


    1.given a having odd number 1s initally only then can increase 1s
      else for even cant increase any ones
    2. cnt of a's >= b's
    3. conversion always possible given ops
  */
    string a,b;cin>>a>>b;

    int a1=0,b1=0;
    f(i,0,a.size()){
        if(a[i]=='1')a1++;
    }
    f(i,0,b.size()){
        if(b[i]=='1')b1++;
    }

    int a0=a.size()-a1, b0=b.size()-b1;


    if((a1 % 2 == 0 and b1>a1)){
        print("NO");
        return;
    }

    if(b1>(a1 + a1%2)){
        print("NO");
        return;
    }


    print("YES");    

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
