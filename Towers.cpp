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

    int n;cin>>n;
    vector<pair<ll,ll>>arr(n);
    f(i,0,n){
        int x;cin>>x;
        arr[i].first = x;
        arr[i].second = i;
    }
    
    multiset<ll> towers;

    f(i,0,n){
        auto it = towers.upper_bound(arr[i].first);

        if(it == towers.end()){
            towers.insert(arr[i].first);
        }
        else{
            towers.erase(it);
            towers.insert(arr[i].first);
        }
    }

    print(towers.size());

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
