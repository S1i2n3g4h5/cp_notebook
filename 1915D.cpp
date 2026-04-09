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
    try with max possible first
    but before that check the current prefix, suffix break;
  */
    
    int n;cin>>n;
    string s;cin>>s;

    
    deque<string>arr;
    string res="";
    int i=n-1;
    while(!s.empty()){
        int x;
        if(s.back() == 'a'  or s.back() == 'e') 
            x=2;
        else    
            x=3;
            
        while(x--){
            res += s.back();
            s.pop_back();
        }
        res+='.';
    }

    res.pop_back();
    reverse(res.begin(), res.end());
    cout << res;
    cout << "\n";

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
