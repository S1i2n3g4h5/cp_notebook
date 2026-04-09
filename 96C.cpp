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


const bool multipleTestCases = 0; 

void solve(){
  /*
    so need to find the forbidden substring in the final team name
    and replace the forbidden chars with given char
    but if already present then replace with next lexigraphically smallest best character

    so for better implementation feasibility - 
        - first need to keep track for the forbidden indexes available
        - decide on the replacemnt char incase the bstchar present
        - do replacement

  */

    int n;cin>>n;
    vector<string>forbidden(n);
    f(i,0,n)cin>>forbidden[i];
    string W;
    char best_char;
    cin>>W>>best_char;

    
    vector<bool> chg(W.size(),0);
    string lowerW = W;
    transform(all(lowerW), lowerW.begin(), ::tolower);


    for(string s:forbidden){
        string lowS = s;
        transform(all(lowS) ,lowS.begin(), ::tolower);

        auto pos = lowerW.find(lowS,0);
        while(pos != string::npos){
            // put val so later on changing..
            f(i,pos, pos+lowS.size()){
                chg[i]=1;
            }
            pos = lowerW.find(lowS, pos+1);
        }

    }

    
    // incase the curr char already present so need anotehr replacement lexigraphically smaller
    char antchr;
    if(best_char == 'a')
        antchr = 'b';
    else{
        antchr='a';
    }


    f(i,0,W.size()){

        if(chg[i]){

            bool isUpper = isupper(W[i]);
            char currLow = tolower(W[i]);
            
            char replacement = (best_char != currLow ? best_char : antchr);

            if(isUpper){
                W[i] = toupper(replacement);
            }
            else{
                W[i] = replacement;
            }

        }

    }


    print(W);

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