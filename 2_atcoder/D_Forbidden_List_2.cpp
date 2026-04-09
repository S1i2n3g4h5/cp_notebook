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
  
    int N,Q;cin>>N>>Q;
    vector<ll>A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    
    sort(A.begin(), A.end());


    while(Q--){
        ll X,Y;cin>>X>>Y;

        ll low=X, high=X+Y+N; 

        while(low < high){
            ll mid = low + (high-low)/2;

            ll blocked = upper_bound(A.begin(), A.end(), mid) - lower_bound(A.begin(), A.end(), X);
            ll missing = (mid - X + 1) - blocked;


            if(missing >= Y) 
                high = mid;
            else 
                low = mid+1;
        }

        print(low);
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