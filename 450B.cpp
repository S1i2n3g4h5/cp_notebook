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

    ll x,y;cin>>x>>y;
    ll n;cin>>n;
    n--;

    vector<ll> arr = {x,y,y-x,-x,-y,x-y};

    if(arr[n%6] <0){
        print(1000000007+arr[n%6]);
    }
    else{
        print(arr[n%6] %1000000007);
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
