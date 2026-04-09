#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = 0;


void solve(){       
    /**/
    ll n,k,x;cin>>n>>k>>x;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];

    sort(arr.rbegin(), arr.rend());

    
    vector<ll> pref(n+1, 0);
    f(i, 0, n) pref[i+1] = pref[i] + arr[i];


    for(ll m = 1; m <= n; m++){
        ll t = m - (n - k);  
        if(t <= 0) continue;

        ll worstSake = pref[m] - pref[m - t];

        if(worstSake >= x){
            print(m);
            return;
        }
    }

    print(-1);
    
    return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
