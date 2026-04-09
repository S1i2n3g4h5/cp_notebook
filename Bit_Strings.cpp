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



const bool multipleTestCases = 0;

ll MOD = 1e9+7ll;

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power & 1){
            result = (result*base) % MOD;
        }

        base = (base*base) % MOD;
        power = power>>1ll;
    }
    return result;
}


void solve(){       

    ll n;cin>>n;

    print(fast_power(2,n)%MOD);

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
