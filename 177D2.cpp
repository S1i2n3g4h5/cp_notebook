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

    sliding windows starts s=0, ends at s=n-m;
    for specific shift s, b[j] aligns with elemtn a[i] if
        i = s+j;
        j = s-i;

    and we know, 0<= s <= n-m;
    and maxmimum ossible j occurs at s[0], j<=i 
    and minimum possible j occurs at j>= i - (n-m)
    and array b constraints for j ->  0<= j <= m-1;

    so i means, L = max(0, i-n+m)
                R = min(m-1, i)



    ----------------

    another appraoch using difference array

  */

    ll n,m,c;cin>>n>>m>>c;
    vll a(n),b(m);
    f(i,0,n)cin>>a[i];
    f(i,0,m)cin>>b[i];


    //____________________________________________
    // vll pf(m+1,0);
    // f(i,0,m)
    //     pf[i+1] = pf[i] + b[i] ;   
    
    
    // f(i,0,n){
        //     ll l = max(0ll, i-n+m);
        //     ll r = min(m-1, (ll)i);
        
        //     a[i] = (a[i] + pf[r+1] - pf[l])%c;
        
        // }
    //____________________________________________

    vll diff(n+1,0);
    f(j,0,m){
        int l = j;
        int r = n-m+j;

        diff[l] += b[j];
        diff[r+1] -= b[j];
    }

    ll currsm=0;
    f(i,0,n){
        currsm += diff[i];

        a[i] = (a[i] + currsm)%c;
    }

    f(i,0,n)
        cout << a[i] << " ";
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