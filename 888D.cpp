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
    Counting permutations where at least n-k elements are in their correct spots pi=i
    
  */
  
    ll n,k;cin>>n>>k;

    // permutate
    vector<ll> d={1,1,2,9};
    
    auto ncr = [&](ll n, ll r){
        ll numerator=n;
        f(i,1,r){
            numerator *= ( n - i);
        }
        ll denominator =1;
        while(r>0){
            denominator *=r;
            r--;
        }
        return numerator / denominator;
    };

    ll ans = 1;
    f(i,1,k){
        // combination n permutate with possibile combinations which later can be dearranged
        ans += ncr(n,i+1) * d[i];
    }
    

    print(ans);
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
