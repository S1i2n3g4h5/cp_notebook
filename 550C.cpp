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
    since this problem smells strong DP, but cant do it cuz didnt learnt DP

    sos will be going brute force way of o(n^3) by checking if digit exits
    1 digit, 2 digit, 3 digit   divisible by 8;

  */

  string s;cin>>s;
    int n=s.size();


    // single 
    f(i,0,n){
        if(s[i] == '0' or s[i] == '8'){
            print("YES");
            print(s[i]);
            return;
        }
    }


    // double
    f(i,0,n){
        f(j,i+1,n){
            if(((s[i] - '0')*10 + (s[j]-'0')) % 8 == 0){
                print("YES");
                print(((s[i] - '0')*10 + (s[j]-'0')));
                return;
            }
        }
    }


    // triple
    f(i,0,n){
        f(j,i+1,n){
            f(k,j+1,n){

                if(((s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0')) % 8 == 0){
                    print("YES");
                    print(((s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0')));
                    return;
                }

            }
        }
    }


    print("NO");

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
