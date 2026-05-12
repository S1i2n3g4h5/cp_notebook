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
    swapping is done wiht the left of current elemnt
    choosing anytig except 0 or leftmost number

    and since the max possible distance on can go it atmst 9 positions
    so it slike a window of 9 to ensure which goes where

  */

    string s;cin>>s;
    int n=s.size();


    f(i,0,n){
        int best_digit=(s[i] - '0');
        int best_idx=i;

        f(j,i+1,min(i+10,n)){
            int currdigit = (s[j] - '0');
            int potential_val = currdigit - (j-i);
            if(potential_val <= 0){
                continue;
            }

            if(potential_val > best_digit){
                best_digit = potential_val;
                best_idx = j;
            } 
        }

        // moving
        if(best_idx != -1){
            s.erase(s.begin() + best_idx);
            s.insert(s.begin() + i, (char)(best_digit + '0'));
        }

    }


    print(s);

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