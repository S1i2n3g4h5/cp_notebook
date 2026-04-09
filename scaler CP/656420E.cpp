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

bool solve(){

  

    int n,m;cin>>n>>m;
    vector<pair<ll,ll>> songs(n);
    f(i,0,n){
        cin>> songs[i].first >> songs[i].second;
    }
    vector<ll> moments(m);
    f(i,0,m) cin>> moments[i];

    vector<ll> prefix_sum(n);
    ll total =0;
    f(i,0,n){
        total += songs[i].first * songs[i].second;
        prefix_sum[i] = total;
    }



    f(i,0,m){

      ll moment = moments[i];

        int left =0, right = n-1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if (prefix_sum[mid] >= moment){
                ans = mid;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }

        print(ans +1);
    }

    
    return 1;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    while(t--){
      solve();
    }
    return 0;
}   