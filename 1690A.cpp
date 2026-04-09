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

    ll n;cin>>n;

    ll a,b,c;
    a=n/3;
    b=n/3;
    c=n - (a + b);


    while(c<=b or c<=a or b<=a){
        if(c<=b){
            if(a>1){

                c++;
                a--;
            }
            else{
                c++;
                b--;
            }

        }
        if(b<=a and a>1){
            b++;
            a--;
        }
    }

    print(b, " ", c, " ", a);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
