/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
  ((cout << args << " "),...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i,a,b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



// ______________________________________________________
long long fast_power(long long base,long long power,long long  MOD=1e9+7ll){
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
    simulate for every possible st playerr
    
  */

    int n;cin >> n;
    vll a(n);
    f(i,0,n){
        cin>>a[i];
    }

    ll S=accumulate(all(a), 0ll);

    set<ll> wplr;
    f(start,0,n){
        vll cur_a = a;
        
        int p = start;
        int eaten=0;
        
        while(eaten < S){
            if(cur_a[p] > 0){
                cur_a[p]--;
                
                eaten++;
        
                if(eaten == S){
                    wplr.insert(p);
        
                    break;
                }
            }

            p =(p+1)%n;
        }
    }

    print(wplr.size());

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
