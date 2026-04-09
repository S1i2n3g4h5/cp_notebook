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



const bool multipleTestCases = false;

ll gcd(ll a, ll b){
    if (b==0)return a;
    return gcd(b,a%b);
}

bool solve(){
    int n;cin>>n;
    vector<ll> a(n);
    f(i,0,n)cin>>a[i];

    ll gcdval = a[0];
    f(i,1,n){
        gcdval = gcd(a[i], gcdval);
    }

    // print(gcdval);
    
    
    if (gcdval == 1 ){
        print(gcdval);
        return 1;
    }

    
    int cnt=2;
    for(ll i=2;i*i<=gcdval;i++){
        if (gcdval%i==0){
            cnt+=2;
            if (i == gcdval/i)
                cnt--;

        }
        
    }
    
    print(cnt);

  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   