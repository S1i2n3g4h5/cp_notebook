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


void solve(){
    
    int n,m;cin>>n>>m;
    vector<int>arr(n),p(m);
    f(i,0,n)cin>>arr[i];
    f(i,0,m){
        cin>>p[i];
        p[i]--;
    }
  

    while(true){
        bool any_swapping=0;

        f(i,0,m){
            if (p[i]+1 < n){
                if (arr[p[i]] > arr[p[i]+1]){
                    int tmp=arr[p[i]];
                    arr[p[i]] = arr[p[i]+1];
                    arr[p[i]+1]=tmp;
                    any_swapping=true;
                }

            }
        }

        if(!any_swapping)break;

    }
    
    // chk invariant
    bool incr=true;
    f(i,0,n-1){
        incr &= arr[i]<=arr[i+1];
    }

    if(incr)print("YES");
    else{
        print("NO");
    }
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