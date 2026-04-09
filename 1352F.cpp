/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 1; 

void solve(){
  /*
    if n2=0 the its just either all 0s  or 1s (cuz its mandatory property)
    
    
  */

    int all_zero,single_one,all_one;cin>>all_zero>>single_one>>all_one;

    if(single_one==0){
        if(all_zero){
            cout << (string(all_zero+1,'0'))<<"\n";
        }
        else{
            cout<<(string(all_one+1,'1')) << "\n";
        }
        return;
    }

    
    string s="";
    
    s += string(all_one+1,'1');
    
    s += string(all_zero+1,'0');
        

    f(i,0,single_one-1){
    
        if(s.back() == '0'){
            s += "1";
        }
        else{
            s += "0";
        }
    }


    cout << s << "\n";
    
}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}