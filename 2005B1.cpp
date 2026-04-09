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
const bool multipleTestCases = 1;


void solve(){
  /*
    constraints 
        m=2   q=1;
        possible moves withint [1,n]


  */
    
    ll n,m,q;cin>>n>>m>>q;
    
    ll a,b;cin>>a>>b;
    ll t1 = min(a,b);
    ll t2 = max(a,b);
    ll boy;cin>>boy;


    ll moves;
    if(t1 < boy and boy < t2){    // 1{    T1 ....  B ... T2      }n
        ll boy_final = (t1+t2)/2;
        moves = min(abs(t1 - boy_final), abs(t2 - boy_final)); 
    }
    else if(t1 < t2 and t2 < boy){    // 1{   T1 ... T2 .. B     }n
        ll boy_final = n;
        moves = abs(boy_final - t2);
    }
    else{   // 1{    B ... t1 ... t2   }n
        ll boy_final = 1;
        moves = abs(boy_final - t1);
    }

    print(moves);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
