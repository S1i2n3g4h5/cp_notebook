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
    since the sum is not changing then its always possible to divide n ints into equality 
    if completely divisible 
    else its atleast n-1
  */

    int n;cin>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];

    
    ll total = accumulate(arr.begin(), arr.end(), 0LL);
    
    if(total % n == 0){
        print(n);
    }
    else{
        // here since its not completely divsible hence 1 digit not same
        print(n - 1);
    }


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
