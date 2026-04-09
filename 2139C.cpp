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
    ll k,x;cin>>k>>x;
    k = 1ll<<k;

    ll y = k*2 - x;

    if(!x or k*2 == x){
        print(-1, "\n");
        return;
    }

    vector<int>ops;
    while(x != k){
        if(x>y){
            x-=y;
            y*=2;
            ops.push_back(2);
        }
        else{
            y-=x;
            x*=2;
            ops.push_back(1);
        }
    }

    print(ops.size());
    for(int i=ops.size()-1;i>=0;i--)
        cout << ops[i] << " ";
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
