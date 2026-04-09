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
    greedily simultaing the last element to be chosen from each set
  
  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    if(n == 1){
        print(0);
        return;
    }


    ll penalty = 0;
    ll last_s=1e9, last_t=1e9;

    f(i,0,n){

        if(arr[i] <= last_s and arr[i] <= last_t ){
            if(last_s < last_t){
                last_s = arr[i];
            }
            else
                last_t = arr[i];
        }
        else if(arr[i] > last_s and arr[i] > last_t){
            penalty++;

            if(last_s < last_t){
                last_s = arr[i];
            }
            else{
                last_t = arr[i];
            }

        }
        else{
            if(arr[i] <= last_s)
                last_s = arr[i];
            else{
                last_t = arr[i];
            }
        }

    }

    print(penalty);


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
