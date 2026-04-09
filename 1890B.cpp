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
    -> no when the t is dup full ( edge case when s already good annd 0 ops req)

    -> trying implmenting this but during insertion checking if thed edge collide then also NO
  */

    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;


    bool good=1;
    f(i,0,n-1){
        good &= (s[i] != s[i+1]);
    }

    if(good){
        print("Yes");
    }
    else{

        // Check if t is not same
        f(i,0,m-1){
            if(t[i] == t[i+1]){
                print("No");
                return;
            }
        }


        //brute force the way
        f(i,0,n-1){
            if(s[i] == s[i+1]){
                if(s[i] == t[0] || s[i] == t[m-1]){
                    print("No");
                    return;
                }

            }
        }
        print("Yes");
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
