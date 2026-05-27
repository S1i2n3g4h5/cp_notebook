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
    since the realtino is ->
        max - min = gcd(arr)

    we now that gcd(arr) diides both max,min aswell, hence it will divide max-min realtion aswell
    and since gcd has to divide min perfectly gcd can nver be greater than min.
        gcd <= min

        => max - min = gcd
        => max - min <= min
        => max <= 2min

    and also that max vlaue cant be <= min(arr), cuz then the array conditions wont satisfy

    possible vals for max -> {m,2m}   m->min

    also following this condiiton we cancheck there should not be more or less than 2 distinct numbers int he selected array range, cuz that can disort the gcd


  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    ll ans=0;

    f(i,0,n-1){
        if(arr[i] % (arr[i] - arr[i+1]) == 0)
            ans++;
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