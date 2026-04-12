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
    so given we got ai
    then conditions are thsi - > let bi = 2^ai
        then count such pairs such that bi^bj = bj^bi

    simplify this ->  2^(ai*2^aj) = 2^(aj*2^ai);    
    after simplify with log -> ai*2^aj = aj*2^ai
                            -> ai/aj = (2^ai)/(2^aj)
                            -> ai/(2^ai) = aj/(2^aj)
        so this is like f(x) = x/(2^x)


    dry running f(x) we find that for only x=1,2 the value is same else (i.e. f(1) = f(2) = 0.5   (both same cuz the pair we needed)) all keeps decreasing which eans 
    only for f(x) with x=1,2 the answer possible
    and also for those duplicates only...


    SO THIS ALL BOILS DOWN TO basic maths and hashing only. 


        MAGNIFICIENT PROBLEM  d=====(￣▽￣*)b

  */

    ll n;cin>>n;
    map<ll,ll>mp;
    f(i,0,n){
        ll x;cin>>x;
        mp[x]++;
    }

    ll ans=0;
    for(auto [val, cnt]:mp){
        if(cnt >= 2){

            ans += (cnt * (cnt-1) / 2);

        }
    }

    ans += ((mp[1]) * (mp[2]));


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