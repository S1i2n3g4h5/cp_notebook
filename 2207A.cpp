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
    
    simulating the results
  */
  
    int n;cin>>n;
    string s;cin>>s;


    while(true){
        bool chg=false;

        f(i,1,n-1){
            if(s.substr(i-1,3) == "101"){
                s[i]='1';
                
                chg=1;

            }
        }
        
        // print(s);

        if(!chg) break;
    }   


    int min_ones = count(all(s),'1');
    int i=0;

    while(i<n-2){
        if(s.substr(i, 3) == "111"){
            // print("found ", i, min_ones);
            min_ones--;
    
            i++;
        } 
        
        i++;
    }

    print(min_ones, count(all(s), '1'));
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