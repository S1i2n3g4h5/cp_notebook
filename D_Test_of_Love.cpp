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
    k

  */

    ll n,m,k;cin>>n>>m>>k;
    string s;cin>>s;

    s = "L" + s + "L";
    ll curr=0;
    bool possible = true;

    while(curr < n+1){
        if(s[curr] == 'L'){
            if(curr + m >= n+1){
                curr = n+1;
                break;
            }

            bool found_log = false;
            for(int nextpos=curr+m;nextpos>curr;nextpos--){
                if(s[nextpos] == 'L'){
                    found_log = true;

                    curr = nextpos;
                    break;
                }
            }

            if(!found_log){
                curr += m;
                if(s[curr] == 'C'){
                    possible = false;
                    break;
                }
            }
        }
        else if(s[curr] == 'W'){
            curr++;
            k--;
            if(k < 0 or s[curr] == 'C'){
                possible = false;
                break;
            }
        }
    }


    if(possible and k>=0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

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