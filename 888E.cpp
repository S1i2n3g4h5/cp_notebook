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
  /*
    usaco.guide/gold/meet-in-the-middle?lang=cpp

    Just got to learn the meet-in-the-middle technique 
    so splitting up the things and generating all the subsets
    then finding the max mod val possible from the generation

    -> iterative subset generation code

    -> main logic into the lower_bound search like to connect the left,right vectors
       together, so the first elem of both will be zero (fallback case when nothign found);
    
    -> for left[i] > mod val just wrap it back to be into the range...

    -> 

  */

    ll n,mod;cin>>n>>mod;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    auto subset_sums = [&](ll l, ll r){
        ll n = r-l+1;
        vector<ll>res;

        f(i,0,1ll<<(n)){
            ll sm=0ll;
            f(j,0,n){
                if(i & (1ll<<j)){
                    sm += (arr[l + j]%mod);
                    sm %= mod;
                }
            }
            res.push_back(sm);
        }
        return res;
    };

    vector<ll>left,right;
    left = subset_sums(0, n/2 - 1);
    right = subset_sums(n/2, n - 1);

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    // print(*left.rbegin(), " ", *right.rbegin());
    ll ans=0;
    for(auto i : left){
        if(i> mod){
            i = i%mod;
        }
        auto it = lower_bound(right.begin(), right.end(), mod - i);

        if(it != right.begin()){
            --it;
            ans = max(ans,(i + *it)%mod);
        
        }
        
    }
    
    print(max(ans, (*left.rbegin() + *right.rbegin())%mod));
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
