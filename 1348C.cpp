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

    only 2 cases possibel - 
    1. all chars same when distributed among k strings;
    2. some cdiffernt chars emrege when trying to distribute.


    for case 1 the asnwer is same so output that.
    but for case 2, when enountered diff chars, just put all chars inot this current string and output
    
  */

    ll n,k;cin>>n>>k;
    string s;cin>>s;

    sort(all(s));
    

    if(s[0] != s[k-1]){
        print(s[k-1]);
        return;
    }


    string ans = "";
    ans += s[0];

    if(k<n){
        if(s[k] == s[n-1]){
            // rem chars same?
            
            int cnt = (n-1)/k;
            ans += string(cnt, s[k]);
        }
        else{
            // rem chars difff;

            ans += s.substr(k);
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