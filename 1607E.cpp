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
    instead of starting to follow directly we do reverse thing

    we assume to be 1,1 as best posistion and try aking space for moves

  */

    ll n,m;cin>>n>>m;
    string s;cin>>s;


    int curr_r=0, curr_c=0;
    int min_r=0,min_c=0,max_r=0,max_c=0;

    int start_r=1, start_c=1;

    for(char c:s){

        if(c == 'L') curr_c--;
        else if(c == 'R') curr_c++;
        else if(c == 'D') curr_r++;
        else if(c == 'U') curr_r--;


        int nxt_min_r = min(min_r, curr_r);
        int nxt_max_r = max(max_r, curr_r);
        int nxt_min_c = min(min_c, curr_c);
        int nxt_max_c = max(max_c, curr_c);


        // within bounds?
        if(nxt_max_r - nxt_min_r + 1 > n or nxt_max_c - nxt_min_c + 1 > m){
            break;
        }

        min_r = nxt_min_r;
        max_r = nxt_max_r;
        min_c = nxt_min_c;
        max_c = nxt_max_c;


        // here we make the shift like if we need out of range like -3 then to adjust we do 1- (-3) => 4 which results into the start posistion (1 (min))
        start_r = 1-min_r;
        start_c = 1-min_c;

    }


    print(start_r, start_c);

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