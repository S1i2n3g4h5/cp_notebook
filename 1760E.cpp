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
    best cnadidates to flip are - 
        0 from the 1st
        1 from the end
        initial inversion count

    

  */

    int n;cin>>n;
    vll arr(n);
    int one_idx=-1,zero_idx=-1;
    f(i,0,n){
        cin>>arr[i];
        
        if(arr[i] == 1)
            one_idx = i;

        if(arr[i] == 0 and zero_idx == -1)
            zero_idx = i;
    }

    auto inversion_count = [&](auto arr){
        ll one=0,ans=0;
        f(i,0,n){

            if(arr[i] == 1)one++;
            else{
                ans += one;
            }

        }

        return ans;
    };


    ll ans = inversion_count(arr);
    
    if(zero_idx != -1){
        arr[zero_idx] = 1;
        ans = max(ans, inversion_count(arr));
        arr[zero_idx] = 0;
    }
    if(one_idx != -1){
        arr[one_idx] = 0;
        ans = max(ans, inversion_count(arr));
        arr[one_idx] = 1;
    }


    print(ans);

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