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
  
  constraint limited ot 5k.. o(n2) possible
  -> reverse atmost 1 sbarrray of A

  so need ot check for the max contribution taht is allowed by Ai for each Bi
  
  so instead of rebuilding reversed subarrays again n again
  we just need to expand from center, like i each step we just need to exand form center
  for both odd,een length subarray and only will be adding l-1,r+1  elmeent during expansion to verify the answer


  so in the new formula, Al-1 used to multiply Bl-1, but in new expanded reversed state, 
  it will swap places and multiply Br+1
  similarly Ar+1 used to be with Br+1, ub tin new it will mltiply Bl-1


  */

  int n;cin>>n;
  vll a(n),b(n);
  f(i,0,n)cin>>a[i];
  f(i,0,n)cin>>b[i];


  ll basesum=0;
  f(i,0,n){
    basesum += (a[i] * b[i]);
  }


  ll ans = basesum;

  f(i,0,n){
    // --- ODD
    ll currsm = basesum;
    int l = i-1;
    int r = i+1;

    while(l>=0 and r<n){
      currsm = currsm - (a[l]*b[l] + a[r]*b[r]) + (a[l]*b[r] + a[r]*b[l]);
      
      ans = max(ans, currsm);
      l--;
      r++;
    }


    // --- EVEN
    currsm = basesum;
    l = i;
    r = i+1;
    while(l>=0 and r<n){
      currsm = currsm - (a[l]*b[l] + a[r]*b[r]) + (a[l]*b[r] + a[r]*b[l]);

      ans = max(ans, currsm);
      l--;
      r++;

    }

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