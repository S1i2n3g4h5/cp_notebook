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
void solve() {
    /*
        k<=n is easy
        main thing is k>n
        
        with k>n, we got surity that each ai will increase once atleast
        it will be like k,k-1,k-2...   to   inrceasing order array til k

         to causing the least damagae we use extra moves in parise on same leemnt
         like lets say operation 10,11 on same number
         => value + 10 -11   => value-1
         hence we just required to pay the -1 debt only!


        << water leveling mathematicall forumla >> 
    */
    
    
    ll n,q; cin>> n >> q;
    vll a(n);
    f(i, 0, n) cin >> a[i];
    sort(all(a));

    
    while(q--){
        ll k;cin>>k;


        if(k<=n){
            ll res=2e18;
            f(i,0,n){
                if(i<k)
                    res = min(res ,a[i] + (k-i));
                else
                    res = min(res,a[i]);
            }

            cout << res << " ";

            continue;
        }


        // k>n
        ll effective = ((k%2 == n%2) ? n : n-1);
        vll b=a;
        ll mn=2e18;

        f(i,0,effective)
            b[i] += (k-i);
        f(i,0,n)
            mn = min(mn, b[i]);

        
        ll extra =0;
        f(i,0,n)
            extra += (b[i] - mn);

        // finding how many -1 decrements to apply more
        ll debt = (k-effective) / 2;
        if(debt <= extra)
            cout << mn << " ";
        else{
            ll rem = debt - extra;
            // pairing (incr,decr) ops
            cout << mn - (rem + n-1)/n << " ";
        }

    }

    cout << "\n";

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