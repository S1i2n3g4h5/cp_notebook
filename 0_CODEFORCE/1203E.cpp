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
    int n;cin>>n;
    vector<int>a(n);
    map<int,int>f;
    f(i,0,n){
        cin>>a[i];
        f[a[i]]++;
    }
    sort(a.begin(), a.end());

    /*
    loop from highest to lowest then -
        1. if a[i] not in newarr then append
        else if (a[i]+1) not in newarr then append
        else if (a[i]-1) not in newarr then append

        *condition for decr must not reach 0

        just follow this algorithm for all steps;
    */
    unordered_set<int> used;
    used.reserve(n);

    int ans = 0;


    for (int i=n-1; i>=0; i--) {
        int x=a[i];
        if(!used.count(x+1)){
            used.insert(x+1);
            ans++;
        }
        else if(!used.count(x)){
            used.insert(x);
            ans++;
        }
        else if(x-1 > 0  and !used.count(x-1)){
            used.insert(x-1);
            ans++;
        }
    }

    cout << ans << "\n";
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