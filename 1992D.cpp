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

    both greedy and dp seems possible.
    lets try with greedy once, then trying for DP solution

    ---

    try to jump when possible log to log jump index keeping
    when i land on log L i need to check next log distance if pssible 
    then directly log else need to swim and make sure doenst run out of M 
    and also no crocdile during swim




  */

    ll n,m,k;cin>>n>>m>>k;
    string s;cin>>s;

    int i=-1;

    while(i<n){
        // Trying to jump to farthest L
        bool jumped = false;
        for(int step=m;step>= 1;step--){
            int next_step = i + step;

            if(next_step >= n){
                cout << "YES" << "\n";
                return;
            }
            
            if(s[next_step] == 'L'){
                i = next_step;
                jumped = true;
                break;
            }
        }


        if(jumped){
            continue;
        }



        // since no next logs, lets just SWIM ...
        i++;
        if(i >=n or s[i] == 'C'){
            cout << "NO" << "\n";
            return;
        }

        if(s[i] == 'W'){
            k--;

            if(k<0){
                cout << "NO" << "\n";
                return;
            }
        }
        
    }


    cout << "YES" << "\n";

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