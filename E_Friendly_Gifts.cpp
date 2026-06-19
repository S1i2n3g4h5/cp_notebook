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

  */

  ll n;cin>>n;
  vector<int> arr(n);
  f(i,0,n)cin>>arr[i];

  
  int max_idx = (n+1)*(n+1);
  vector<int> min_pos(max_idx,n+1),max_pos(max_idx, -1);
  vector<int> seen(n+1,0);
  int token = 0;

  // finding all good subsegments..
  f(i,0,n){
    token++;

    ll mn = arr[i], mx = arr[i];

    f(j,i,n){
      // if hitting duplicate then break it
      if(seen[arr[j]] ==token){
        break;
      }

      seen[arr[j]] = token;
      mn = min((ll)arr[j], mn);
      mx = max((ll)arr[j], mx);


      // is perfect continguus?
      if(mx - mn == j-i){
        ll flat_idx = mn*(n+1) + mx;
        min_pos[flat_idx] = min((ll)min_pos[flat_idx], (ll)i);
        max_pos[flat_idx] = max((ll)max_pos[flat_idx], (ll)i);
      }

    }

  }


  ll ans=0;
  bool found=false;

  for(ll L=n/2;L>=1;L--){

    for(ll v=1;v+2*L -1 <= n;v++){
      ll flat1 = v*(n+1) + (v + L-1);
      ll flat2 = (v+L)*(n+1) + (v+2*L-1);


      // if either value block des exist in array, skip...
      if(min_pos[flat1] == n+1 or min_pos[flat2]==n+1){
        continue;
      }


      ll a_min = min_pos[flat1];
      ll a_max = max_pos[flat1];
      ll b_min = min_pos[flat2];
      ll b_max = max_pos[flat2];


      /*
        overlap verifcaiotn-
        either righmost occurance f A is compeltel to the right of the leftmost of B
        or vice versa
      */
      if(a_max >= b_min+L or b_max>=a_min+L){
        found=true;
        break;
      }

    }

    if(found){
      ans = L;
      break;
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