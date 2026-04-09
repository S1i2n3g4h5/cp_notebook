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



const bool multipleTestCases = 1;


void solve(){
  
    ll n,k,q;cin>>n>>k>>q;
    vector<ll> temp(n);
    f(i,0,n){
        cin>>temp[i];
    }


    ll total=0;
    ll len=0;

    f(i,0,n){
        if(temp[i] <=q){
            len+=1;
        }
        else{
            if(len>=k){
                ll dif=len-k+1;
                total += (dif *(dif+1))/2;
            }
            // total += (len -k +1) * (len-k+2);
            
            len =0ll;
        }
    }
    
    if(len>=k){
        ll dif=len-k+1;
        total += (dif *(dif+1))/2;
    }
    // total += (len -k+1) * (len-k+2);


    print(total);
    
  
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


