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

bool verify_array(int n, vll a) {
    if (a.size() != 4 * n) {
        cerr << "Error: Array length is not 4 * n" << endl;
        return false;
    }


    vector<vector<int>> pos(n + 1);
    
    for (int i = 0; i < a.size(); ++i) {
        int x = a[i];
        if (x < 1 || x > n) {
            cerr << "Error: Array contains element " << x << " which is out of bounds [1, " << n << "]" << endl;
            return false;
        }
        pos[x].push_back(i);
    }


    for (int x = 1; x <= n; ++x) {
        if (pos[x].size() != 4) {
            cerr << "Error: Number " << x << " appears " << pos[x].size() << " times instead of 4." << endl;
            return false;
        }

        int d1 = pos[x][1] - pos[x][0];
        int d2 = pos[x][2] - pos[x][1];
        int d3 = pos[x][3] - pos[x][2];

        if (d1 == d2 || d2 == d3 || d1 == d3) {
            cerr << "Error: Number " << x << " has non-distinct distances: " 
                 << d1 << ", " << d2 << ", " << d3 << endl;
            return false;
        }
    }

    return true; // Passes all checks!
}

void solve(){
  /*

  */

  ll n;cin>>n;

  vll arr;

  vll forward(n);
  f(i,0,n){
      forward[i] = i+1;
  }

  vll backward(n);
  f(i,0,n){
      backward[i] = n-i;
  }


  if(n % 2 != 0){
      ll m = (n + 1)/2;
      swap(backward[n - m], backward[n - m - 1]);
  }


  vll ans;
  ans.insert(ans.end(), all(forward));
  ans.insert(ans.end(), all(forward));
  ans.insert(ans.end(), all(backward));
  ans.insert(ans.end(), all(forward));


  f(i,0,ans.size()){
      cout << ans[i] << (i+1 == (ll)ans.size() ? "" : " ");
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