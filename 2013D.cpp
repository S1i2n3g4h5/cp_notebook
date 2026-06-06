/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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


const bool multipleTestCases = 1; 

void solve(){
  /*

    so it slike carrying over soe digits form i-1 to i+1
    we cna make the digits negative or positie as mus as many times,
    no restriction on number of operations...

    so goal is to make maximum and minimu elemnt as close as possible


    smeels binary search aswell, like we we fix the maximum possible minimum value L, minimum possible maximum value R.
    so first is of searching off for the L, then R...  for L, that is arr[i] >= L for all i
    we know that sum  of all elemtsn remain constant hence this sum is invariant

    so we just keep a debt variable that keeps track of how much debt we got when arr[i] >= L
    and we pay off debt from debt airable when arr[i]  < L

    vice versa for R.

  */

    ll n;cin>>n;
    vll arr(n);
    ll mx = -1e12,mn=1e12;
    f(i,0,n){
        cin>>arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }


    ll ans = mx - mn;
    if(ans == 0){
        print(ans);
        return;
    }


    // Maximum possible minimum
    auto checkL = [&](ll L){
        // distributing as much as possible to auto account for debt aswell
        ll surplus = 0;
        
        f(i,0,n){
            surplus += (arr[i] - L);

            if(surplus < 0){
                return false;
            }
        }
        return true;
    };
    
    ll left = 0, right = mx;
    ll ansL = mx;
    while(left<=right){
        ll mid = left + (right - left)/2;

        if(checkL(mid)){
            ansL = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }


    // Minimum possible maximum
    auto checkR = [&](ll R){    
        ll excess =0 ;
        f(i,0,n){
            excess = max(0ll, excess + arr[i] - R);            
        }

        // while distribution we ensure that at the end arr[n], the excess==0 else it means we got more than to digest
        return excess == 0ll;    
    };
    
    left = 0, right = mx;
    ll ansR = mx;
    while(left <= right){
        ll mid = left + (right - left)/2;

        if(checkR(mid)){
            ansR = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    // print(ansL, ansR);
    print(ansR - ansL);

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