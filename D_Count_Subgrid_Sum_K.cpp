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


const bool multipleTestCases = 0; 

void solve(){
  /*

    counting all possibel subarays wiht total sum == m )given(
    but normal brute force resulting into TLE (that loop of counting eahc subarray...)
    so another better appraohc is to modify this... since we are calculating the 

    and here we get the 2d prefix sum....
      -> pf[r][c] = pf[r-1][c] + pf[r][c-1] - pf[r-1][c-1] + grid
      -> Here we subtracting cuz that box overlapping region cgot added twice...
    
    and the method ot extract -
      -> Range = pf[r2+1][c2+1] - pf[r1][c2+1] - pf[r2+1][c1] + pf[r1][c1]
      -> explanantions = extracting massive box til lthe bottom   pf[r2+1][c2+1]
          subtract entire white region above it   pf[r1][c2+1]
          subtract entire white region to its left   pf[r2+1][c1]
          the starting corner got subtracted twice, add back   pf[r1][c1]

  There are many approahces to this...
  1.frequency based couting
  2.editorial - 3 pointer approach
  3.column prefix , k, k+1 approach

  */

  ll h,w,k;cin>>h>>w>>k;
  vector<string>grid(h);
  f(i,0,h)cin>>grid[i];



  //##################################################################
  //##################################################################
  //##################################################################
  /*
  Since we know that if current runnng sum >k
  and we know that current running sum >= k
    then the answer is just ->   cnt(currsum >= k) - cnt(currsum > k)
  
  column prefix formula between any rows-
    let row=r1,r2 and column=c;

  Now,
    columnSegmentSum = pf[r2+1][c+1] - pf[r1][c+1] - pf[r2+1][c] + pf[r1][c]
  
  ---

  So in the solution below, we know that, sum of submatrix when rearranged ->
    => colsum(c1) + colsum(c2) ... colsum(n)
  hence we are suing sliding window to find the sum>=targetsum then subtracting the leftmost one
  and continuing...
  
  */
  
  // building column prefix
  vector<vll> colpref(w, vll(h+1,0));

  f(c,0,w){
    f(r,0,h){
      colpref[c][r+1] = colpref[c][r] + (grid[r][c] - '0');
    }
  }


  auto count_at_least = [&](ll target_sum){
    if(target_sum<=0){
      return (ll)h*(ll)(h+1)/2ll*(ll)w*(ll)(w+1)/2ll;
    }

    ll count=0;

    f(r1,0,h){
      f(r2,r1,h){

        ll l=0,r=0;
        ll window_sum = 0;
        while(l < w){
          // expand until hits our target
          while(r < w and (r<=l or window_sum < target_sum)){
            window_sum += (colpref[r][r2+1] - colpref[r][r1]);
            r++;
          }

          if(window_sum >= target_sum){
            count += (w - r + 1);
          }

          window_sum -= (colpref[l][r2 + 1] - colpref[l][r1]);
          l++;
        }

      }
    }

    return count;
  };


  // core editorial -> exactly(k) = atleast(k) - atleast(k+1)
  cout << count_at_least(k) - count_at_least(k+1) <<"\n";

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