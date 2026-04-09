#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}
#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


const bool multipleTestCases = false;

bool solve(){

    int n; cin >> n;
    vector<int> a(n);
    
    int sm = 0;
    f(i,0,n){
        cin >> a[i];
        sm += a[i];
    } 
    sort(a.begin(), a.end());

    int req = 0;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        req += a[i];
        cnt++;
        if(req > (sm - req))
            break;
    }

    print(cnt);
    
    return 1;
}

 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    while(t--){
      solve();
    }
    return 0;
}   