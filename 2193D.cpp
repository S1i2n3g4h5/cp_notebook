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
    sorting req
    
    If needed>n ->stop
    else ->slay monster

  */

  int n;cin>>n;
  vector<ll>a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    sort(a.rbegin(), a.rend());


    ll ans=0,needed=0;
    
    f(i,0,n){
        needed += b[i];
        // print(i, " ", needed);
        
        if(needed > n){
            // print("done...", i, ", ", b[i]);
            break;

        }   

        ans = max(ans, a[needed-1] * (i+1));
    
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
