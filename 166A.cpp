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

    int n,k;cin>>n>>k;
    vector<pair<int,int>>arr(n);
    f(i,0,n)cin>>arr[i].first>>arr[i].second;


    sort(arr.begin(), arr.end(), [&](auto p1, auto p2){
        if(p1.first != p2.first){
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    });

    print(count(arr.begin(), arr.end(), arr[k-1]));



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
