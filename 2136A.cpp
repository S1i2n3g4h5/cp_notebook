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

  */
 int a,b,c,d;cin>>a>>b>>c>>d;

    bool first_half_cnd = max(a,b) <= 2*(min(a,b)+1);
    bool sec_half_cnd = max(abs(a-c),abs(b-d)) <= 2*(min(abs(a-c),abs(b-d))+1);

    if(first_half_cnd and sec_half_cnd)
        print("YES");
    else
        print("NO");
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
