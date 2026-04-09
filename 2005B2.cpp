/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 1;


void solve(){
  /*
    possible moves withint [1,n]
    binary search for the optimal moves finding 


  */
    
    ll n,m,q;cin>>n>>m>>q;
    vector<ll>teachers={0ll,n+1};   // setting boundaries... 
    vector<ll>boys(q);
    f(i,0,m){
        ll x;cin>>x;
        teachers.push_back(x);
    }
    f(i,0,q)cin>>boys[i];
    
    sort(teachers.begin(), teachers.end());
    

    // Enough teachers for each student
    for(auto boy:boys){
        auto iter = lower_bound(teachers.begin(), teachers.end(), boy);

        ll ub = *iter;
        --iter;
        ll lb = *iter; 
        
        if(lb == 0){   // { B ... T1
            print(ub-1);
        }
        else if(ub == n+1){    // T2 .... B }
            print(n - lb);
        }
        else{   //   t1 ... B ... t2
            print(min(ub - (ub + lb)/2, (ub + lb)/2 - lb)); 
        }
    }        
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
