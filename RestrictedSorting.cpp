#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = 1;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    f(i, 0, n) cin >> a[i];


    if(is_sorted(a.begin(), a.end())){
        print(-1);
    
        return;
    }



    sort(a.begin(), a.end());


    int ans = 0;
    f(i,0,n-1){
    
        ans = max(ans, a[i+1] - a[i]);
        
        // print(a[i] , " ", a[i+1]);
    }

    print(ans);

}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1; multipleTestCases and cin >> t;
    while(t--){
        solve();
    }
    return 0;
}