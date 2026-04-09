/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 


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


const bool multipleTestCases = 0; 


void solve(){
  /*
    just sorting based on min essays and greedily choosing until the total points diff with the left out is not <=0
  
    its like i need to maximize each ai to max r and just add up that with that how many times its bi involved
*/

    ll n,r,avg;cin>>n>>r>>avg;
    vector<pll> arr(n);

    ll totsum=0.0;
    f(i,0,n){
        cin>>arr[i].first >>arr[i].second;
        
        totsum += arr[i].first;
    }
    
    ll diff = (n*avg) - totsum;
    
    if(diff <= 0) {
        print(0);
        return;
    }

    
    sort(arr.begin(), arr.end(), [](auto &x, auto &y) {
        return x.second < y.second;
    });


    ll ans=0;
    f(i,0,n){
        ll diff_to_max_points = r - arr[i].first;

        ans += (min(diff, diff_to_max_points) * arr[i].second);
        diff -= min(diff, diff_to_max_points);

        if(diff<=0){
            break;
        }
    }

    print(ans);

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
