/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 

bool used[400005]={false};

void solve(){
  /*
    we can utilize a bucket like concept like exploiting the mod x

    like creating 3 arrays a1,a2,a3 each denoting the number values such that a1 contains those a1%x==0, then a2 contains a1%x==1 and so on.

    then for any given q we find its corresponding buckt and fix the min from the bucket thne its easy task to calc mex from here.

    so the core logic into matching numbers found to fill in those missing numbers
    the trick is this ->     target_pos = rem + (bucket_count[rem]*x)

    here the bucketrem stores how many numbers for given remainder is done. 


        -> Mex also got a progressive state that it will either remain same or continue to increase and can never decrease.

  */

    int q,x;cin>>q>>x;
    
    vll bucket_count(x,0);
    int mex=0;

    while(q--){
        ll y;cin>>y;

        ll rem = y%x;

        ll target_pos = rem + (ll)(bucket_count[rem] * x);
        if(target_pos <= 400005){
            used[target_pos] = true;
        }

        bucket_count[rem]++;

        while(used[mex]){
            mex++;
        }

        print(mex);
    }    

}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}
