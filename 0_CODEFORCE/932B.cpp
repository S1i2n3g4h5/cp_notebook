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



const bool multipleTestCases = true;
// vector<vector<int>> data(10, vector<int>(1000001,0));
ll cnt[10][1000001];

ll non_zero(ll n){
    return n==0 ? 1:n;
}

ll f_of_n(ll n){
    if (n<=9)return n;
    ll res = 1LL;
    while(n){
        ll d = n % 10LL;
        if(d) res *= d;
        n /= 10LL;
    }
    return f_of_n(res);
}

void solve(){
  ll l,r,k;cin>>l>>r>>k;

  print(cnt[k][r] - cnt[k][l-1]);
  
  return;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(nullptr);//cout.tie(0);
  int t = 1;multipleTestCases and cin >> t;
  

    // preprocessing ...
    f(i,1,1000001){
        cnt[f_of_n((ll)i)][(ll)i]++;
    }

    f(d,1,10){
      f(i,1,1000001){
        cnt[(ll)d][(ll)i] += cnt[(ll)d][(ll)(i-1)];
      }
    }

    while(t--){  
      solve();
    }  
    return 0;
}   