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
    trying the permutations....
  */

    int n;cin>>n;
    string s;cin>>s;  
    int l=0,r=0,u=0,d=0;  
    f(i,0,n){
        if(s[i]=='L') l++;
        else if(s[i]=='R') r++;
        else if(s[i]=='U') u++;
        else d++;
    }

    // checking if exists..
    // if((l>0 and r==0) or (r>0 and l==0) or (u>0 and d==0) or d>0 and u==0){
    //     print(0);
    //     return;
    // }


    print(2*max({ min(l,r), min(u,d), min(l,r)+min(u,d) }));
    
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
