#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
 
    ll n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];

    // type2
    vector<ll>pf(n);
    pf[0] = arr[0];
    f(i,1,n)
        pf[i] = arr[i] + pf[i-1];
        

    // type1
    sort(arr.begin(),arr.end());
    f(i,1,n){
        arr[i] += arr[i-1];
    }
        

    ll m;cin>>m;
    while(m--){
        ll t,l,r;cin>>t>>l>>r;
        l--;r--;

        if(t==1){
            if(l==0){
                print(pf[r]);
            }    
            else{
                print(pf[r] - pf[l-1]);
            }
        }
        else{
            if(l==0)
                print(arr[r]);
            else{
                print(arr[r] - arr[l-1]);
            }
        }

    }


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