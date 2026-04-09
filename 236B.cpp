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


int nums[1000000LL+1ll];
const bool multipleTestCases = 0;



void solve(){
  ll a,b,c;cin>>a>>b>>c;
   const ll MOD = 1073741824ll;
  ll sm =0ll;
  f(i,1,a+1){
    f(j,1,b+1){
        f(k,1,c+1){
            sm  = (sm%(MOD) + (nums[i*j*k])%(MOD))%(MOD);
        }
    }
  }

  print(sm);
  
  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    

    nums[0]=0;
    for(ll i=1;i<=1000000;i++){
        for(ll j=i;j<=1000000;j+=i){
            nums[j]++;
        }
    }

    while(t--){  
      solve();
    }  
    return 0;
}     


