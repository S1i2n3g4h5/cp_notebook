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
    -> infinite height
    -> arranged into circle (maybe cyclic property to be used)

    max capacity is foudn by taking min of max partition heights on clokc n anti-clock
    cuz change in water height adjacent box cannot exceed the partition height between thmm

    ---



  */

    ll n;cin>>n;
    vll h(n);
    f(i,0,n)cin>>h[i];

    vll ans(n),l(n),r(n);
    f(i,0,n){
        f(d,1,n){
            int idx = (i + d)%n;
            int prvidx = (i+d-1)%n;

            l[idx] = (d==1 ? h[i] : max(l[prvidx], h[prvidx]));
        }

        f(d,1,n){
            int idx = (i-d+n)%n;
            int prvidx = (i-d+1+n)%n;
            r[idx] = (d==1 ? h[idx] : max(r[prvidx], h[idx]));
        }

        ll total=0;
        f(j,0,n){
            if(j == i)
                continue;
            
            total += min(l[j], r[j]);
        }

        ans[i] = total;
    }

    f(i,0,n){
        cout << ans [i]  << " ";
    }
    cout <<"\n";

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