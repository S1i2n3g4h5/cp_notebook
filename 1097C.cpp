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
    instead of brute force implementation, we will use trick to keep track of valid ones
    and which valid ones fro given strings can actually balance out the opp side parantesis

  */

    int n;cin>>n;
    map<int,int>pos,neg;
    int perfect=0;

    f(i,0,n){
        string s;cin>>s;

        int balance=0,min_bal=0;
        for(char c:s){
            if(c=='(')balance++;
            else balance--;
            min_bal = min(min_bal, balance);
        }


        if(balance==0){
            if(min_bal == 0){
                perfect++;

            }
        }
        else if(balance > 0){
            if(min_bal == 0){
                pos[balance]++;
            }
        }
        else{
            if(min_bal == balance){
                neg[-balance]++;
            }
        }

    }


    int pairs = perfect/2;
    for(auto [val, cnt]:pos){
        if(neg.count(val)){
            pairs += min(cnt, neg[val]);
        }
    }


    print(pairs);

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