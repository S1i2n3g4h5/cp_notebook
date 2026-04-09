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

ll max_len = 1e6+1ll;
vector<bool> precomp(max_len,true); 

void solve(){
  /*
    since constraint so high need to do seive till sqrt(1e12)
    then its common fact to just check given nums sqrt 
    if its there into the sieve then okay else NO;
  */

  ll n;cin>>n;
  vector<ll>arr(n);
  f(i,0,n)cin>>arr[i];


    f(i,0,n){
        // print(precomp[arr[i]]);
        ll x = sqrt(arr[i]);

        if(x*x == arr[i] and x >= 2 and precomp[x]){
            // perfect sq root
            
            print("YES");
            continue;
            
        }

        print("NO");
    }
    

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    

    precomp[0]=0;
    precomp[1]=0;
    f(i,2,max_len){
        if(precomp[i]){
            for(ll j=i*(ll)i;j<max_len;j+=i)   
                precomp[j]=false;
        }
    }

    while(t--){  
      solve();
    }  
    return 0;
}     
