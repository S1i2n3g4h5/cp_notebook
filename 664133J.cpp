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
    
    ll n,k;cin>>n>>k;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];
    

    ll ans = 0ll;

    ll and_sum = -1;
    ll target = k-1;
    
    f(i,0,n){
        and_sum &= arr[i];
    }
    // print(and_sum);
    // return;
    
    
    int cnt=0;
    
    f(i,0,64) {

        if((and_sum >> i) & 1) 
           cnt++;
    }

    if(target >= (1ll << cnt)){
        print(-1);
        return;
    }

    
    int ith_cnt = 0;
    f(i,0,64){
        if((and_sum >>i) & 1){

            if((target >> ith_cnt) & 1){
            
                ans=ans| (1LL << i);
            }

            ith_cnt++;
        }
    }


    print(ans);

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