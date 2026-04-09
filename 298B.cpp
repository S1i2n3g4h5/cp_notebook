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


void solve(){
  /*
    greedy implementation 
  */

  ll t,x,y,ex,ey;cin>>t>>x>>y>>ex>>ey;
  string s;cin>>s;


    f(i,0,t){
        if(ex==x and y==ey){
            print(i);
            return;
        }
        
        
        // Move
        if(s[i] == 'E' and (abs(x-ex) > abs(x+1-ex))) x++;
        else if(s[i] == 'W' and (abs(x-ex) > abs(x-1-ex))) x--;
        else if(s[i] == 'N' and (abs(y-ey) > abs(y+1-ey))) y++;
        else if(s[i] == 'S' and (abs(y-ey) > abs(y-1-ey))) y--;
        
        
        if(ex==x and y==ey){
            print(i+1);
            return;
        }
        
    }

    print(-1);

  
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
