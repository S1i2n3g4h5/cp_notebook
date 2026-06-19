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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
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

    since the constraints on N -> [4,40];
    meaning some sort of brute force possible;

    and we know that, for 2 a1,a2 to equal,
        a1 - nk = a2 - mk
        a1 - a2 = k(n - m);

    hence instead of trying all possible ocmbinations,
    we will just check if we can take any a2 to a1..
    by brute forcing on N;
    the one wiht max frequqnecy K wins only its its n/2-1 greater than else -1
    
    * doing -1 here cuz the lement we assumed to make all equal to is to be avoided from clacualting into that

    ----

    so its like we treat ai as the baseline, and claculating diff.
    then findig possible divisors of these differences.. cuz if gap is 12 then k could be 12,6,4,3,2,1.
    so keeping frequency of how any times each difvosir appear across all differences ofr current baseline a[i];

    then if any divisor appeart >= n/2-1 then its valid;

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    ll max_freq=0;
    map<ll,ll>mp;
    f(i,0,n){
        mp[arr[i]]++;
        max_freq = max(max_freq, mp[arr[i]]);
    }


    if(max_freq >= n/2){
        cout << "-1\n";
        return;
    }


    ll ans = 1;

    f(i,0,n){

        map<ll,ll>divisor_freq;
        f(j,0,n){
            if(i==j)continue;

            ll diff = abs(arr[i] - arr[j]);
            if(diff == 0)
                continue;

            for(ll d=1;d*d<=diff;d++){
                if(diff % d == 0){
                    divisor_freq[d]++;
                    if(d*d != diff){
                        divisor_freq[diff/d]++;
                    }
                }
            }
        }

        ll elements_alrdy_equal = mp[arr[i]];
        for(auto [val,cnt]:divisor_freq){
            if(cnt + elements_alrdy_equal >= n/2){
                ans = max(ans, val);
            }
        }

    }

    cout << ans << "\n";

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