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
    constraint contains only a,b
    
    invariant depends on the cost minimization 
    so chk both a,b costs

    needs positions for a,b separately then -->>   cst += abs(arr[pos] - arr[i]) - abs(pos - i);

*/

    ll n;cin>>n;
    string s;cin>>s;


    if(s.size()<=2){
        print(0);
        return;
    }

    // find diffs available
    ll diffs=0;
    f(i,0,n-1){
        if(s[i] != s[i+1])
            diffs++;
    }


    if(diffs <=1){
        print(0);
    }
    else{
        vector<ll>a,b;
        f(i,0,n){
            if(s[i]=='a')
                a.push_back(i);
            else
                b.push_back(i);
        }

        auto cost = [&](vector<ll> arr){
            if(arr.empty())
                return 0ll;

            ll cst = 0ll;
            ll pos = arr.size()/2;

            f(i,0,arr.size()){
                cst += (ll)(abs(arr[pos] - arr[i]) - abs(pos - i));
            }
            return cst;
        };
        
        print(min(cost(a), cost(b)));

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
