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
    
    ll n,q;cin>>n>>q;

    vector<ll>arr(n+1);
    f(i,0,n+1){
        cin>>arr[i];
    }


    vector<ll>prefix(n+2,0ll);
    
    f(i,1,n+2){
        prefix[i] = prefix[i-1]+arr[i-1];
    }
    prefix.push_back(0);
    // for(auto p:prefix){
    //     cout << p << " ";
    // }
    
    cout << fixed << setprecision(10);
    // cout << (double)10.0 << endl;
    
    while(q--){

        ll l,r;cin>>l>>r;
        // l--;r--;
        // print(l,",",r);
        // print(prefix[r] - prefix[l]);
        
        // print(prefix[r] - prefix[l], " ", arr[r]);
        print((double)(prefix[r] - prefix[l]) / (double)arr[r] );
        
    }

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
