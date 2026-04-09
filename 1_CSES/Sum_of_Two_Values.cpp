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
    ll n, target;cin>>n>>target;

    vector<pair<ll,ll>> a;
    f(i,0,n){
        ll value;cin>>value;
        a.push_back({value, i+1});
    }


    sort(a.begin(), a.end());

    int l=0, r=n-1;
    while(l<r){
        ll sum = a[l].first + a[r].first;
        if(sum == target){
            print(a[l].second, " ", a[r].second);
            return;
        }
        else if(sum < target) l++;
        else r--;
    }


    print("IMPOSSIBLE");

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