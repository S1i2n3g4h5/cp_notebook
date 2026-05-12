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


const bool multipleTestCases = 0; 

void solve(){
  /*
    2 conditions to satisfy for being the tto drop the array elemtns to zero
        - sum must be even
        - 2*max <= sm

    1st condition is intuitive but for the 2nd condition we need to do some proofs-

    for the 2nd condition, since we are pairing up then, if maxelemnt needs more than 50% it means we wont have any pairs left to pair it up with
    hence checking this condition is useful and important to make sure all the paris are there to evnetually make it zero
    

  */
    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    ll sm = accumulate(all(arr),0ll);
    ll mx = *max_element(all(arr));


    if(sm%2 != 0 or sm < 2*mx){
        print("NO");

    }
    else{
        print("YES");
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