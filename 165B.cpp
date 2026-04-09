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

    ll n,k;cin>>n>>k;


    auto check =[&](ll v){
        ll sm=v;
        while(v!=0){
            v=v/k;
            sm+=v;
        }
        return sm>=n;
    };

    ll l=0,h=n+1;
    while(l<=h){
        ll mid=  l+(h-l)/2;

        if(check(mid)){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    
    print(h+1);

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
