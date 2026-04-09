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
const bool multipleTestCases = 1;


void solve(){
  /*

  */

  string s;cin>>s;

  
  bool db=false;
    if(s[0] == 'B' or s[s.size()-1]=='B')
        db=1;
    
    f(i,1,s.size()){
        if(s[i-1] =='B' and s[i]=='B')
            db=1;
    }

    
    int curra=0;
    int tota=0;
    vector<int>arr;
    f(i,0,s.size()){
        if(s[i] == 'A'){
            curra++;
            tota++;
        }
        else{
            if(curra>=1)
                arr.push_back(curra);
                curra=0;
            }
    }
    if(curra>=1)
        arr.push_back(curra);


    if(db || arr.size() == 0){
        print(tota);
    }
    else{
        print(tota - *min_element(arr.begin(), arr.end()));
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
