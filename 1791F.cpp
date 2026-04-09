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
#define debug(x) cout<<#x<<" = "<<x<<ln
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


const bool multipleTestCases = 1; 

void solve(){
  /*
    brute force directly cnat works
    
    another observation -> since taking sum of digits converges any bigg number to single digit in less than 3 or so steps (for this max contrains 1e10)

    so we can instead use set to store idx of those array elements those having more than 1 digit remaining

    and using binary search for more optimization to find the 1st index to operate from 


    !! ->  One trap to notice is that, if you set the iterator to some elmentr from set then after removing you cant do itr++ cuz that iterator is erased (as here in code), so need to update directly with the method only

  */

    ll n,q;cin>>n>>q;
    vll a(n);
    f(i,0,n)cin>>a[i];


    auto sm_digits = [&](ll d){
        ll sm=0;
        while(d){
            sm+=d%10;
            d/=10;
        }
        return sm;
    };

    // Putting all indexes having num > 2 digits;
    set<int>idx;
    f(i,0,n){
        if((log(a[i]) + 1) > 1)
            idx.insert(i);
    }

    while(q--){

        int t;cin>>t;
        if(t==2){
            int x;cin>>x;
            x--;

            print(a[x]);
        }
        else{
            int l,r;cin>>l>>r;
            l--;r--;

            auto lbi = idx.lower_bound(l);
            
            while(lbi != idx.end() and *lbi <= r){
                a[*lbi] = sm_digits(a[*lbi]);


                
                // Iterator updation important, cant do updation without else block or after erasing cuz then that iterator wont exists
                if(a[*lbi] < 10){
                    idx.erase(lbi++);
                }
                else{
                    lbi++;
                }

            }

        }

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
