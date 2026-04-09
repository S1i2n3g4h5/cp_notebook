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

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 1; 


void solve(){
  /*
    
  */
 
    ll n,k;cin>>n>>k;
    vector<ll>arr(n);
    f(i,0,n){
        cin>>arr[i];
        arr[i] = arr[i] %k;
    }


    sort(arr.begin(), arr.end());
    
    ll mx= -1;
    int i=0;
    while(i < n-1){
        if(arr[i] == 0){
            i++;
            continue;
        }

        ll cnt=1ll;
        while(i+1 < n  and arr[i] == arr[i+1]){
            cnt++;
            i++;
        }


        mx = max(mx, 1ll*(cnt-1)*k + (k-arr[i]));
        i++;
    }
    
    print(max(0ll, mx + 1));

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