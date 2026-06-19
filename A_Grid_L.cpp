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

// Boost Multiprecision (rare but lifesaving)
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// int128_t  : when ll overflows (products > 1e18)
// int256_t/int512_t/int1024_t : fixed ultra-large integers
// cpp_int : arbitrary precision integer, ideal for n! , Catalan numbers, huge DP counts


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

    since to build nxm grid,
    we require (n+1)*m units for horizonatal
    and (m+1)*n units for vertical

    and since L shaped provide 1horizontal + 1vertical
    hence ->
    => (n+1)m + (m+1)n = 2mn + m + n
    
    -> => 2mn +m +n = p + 2q;

    now,
    => S = p + 2q = 2mn + n + m

    multiple by 2,     -- {cuz S is constant and known}
    2S = 4mn + 2n + 2m
    adding +1 to boht side,
    2S + 1 = 4mn + 2n + 2m + 1
    2S + 1 = 2n(2m + 1) + 2m + 1
           = (2n + 1)(2m + 1)

           
    _______________________________________
    => 2(p + 2q) + 1 = (2n + 1)(2m + 1)
    _______________________________________

    since 2n and 2m will always be even but adding +1 makes it always giving odd,
    hence 2S+1  will be ODD too... hence the factors for n,m value will be ---
    in terms of odd factor A n B --- 
        n = (A-1)/2
        m = (B-1)/2

    and even these n,m will be odd divisors to be iterated over...
    and since, n,m>=1  we cant put A or B = 1 cuz it resutls into n,m = 0;

    and since,
        H = m(n+1)      V = n(m+1)
        then we require atleast qH  and qV     whwere  q is L's 
    e.g.
        p=2,q=10
        lets say n=1,m=7  then, 
            H = 7(2) = 14
            V = 1(8) = 8
        then we know we requie atleast qH and qV...
        q=10, H = 14  ->  10 <=    14   (works)
        q=10, V = 8   ->  10 !(<=) 8    (wrong)

        <you can also draw this arrangement and verify it that way aswell>
    
 
  */

    ll p,q;cin>>p>>q;


    ll S = p + 2*q;
    ll K = 2*S + 1;

    // searching for odd factors of K >=3
    // not checking for k=1 cuz on 1 its giving 0 which violating the n,m constraints
    for(ll d=3;d*d <= K;d++){
        if(K % d == 0){
            ll A = d;
            ll B = K/d;

            ll n = (A-1)/2;
            ll m = (B-1)/2;
            
            ll V = n*(m+1);
            ll H = m*(n+1);

            if(q <= V and q <= H){
                cout << n << " " << m << "\n";
                return;
            }
        }

    }


    cout << "-1\n";

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