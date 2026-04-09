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

    ll n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];
    sort(arr.begin(),arr.end());

    // map<ll,int>done;
    
    // ll mn_cost=1e9;
    // f(i,0,n){
    //     if(done[arr[i]] != 0)continue;
    //     done[arr[i]] = 1;
        
    //     ll curr=0ll;
    //     f(j,0,n){
    //         curr += abs(arr[i] - arr[j]);
    //     }
    //     mn_cost = min(mn_cost, curr);
    // }

    // print(mn_cost);


    //__________ median trick
    ll med=arr[n/2];
    
    ll cost = 0ll;
    f(i,0,n)cost += abs(med - arr[i]);
    
    print(cost);

    
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
