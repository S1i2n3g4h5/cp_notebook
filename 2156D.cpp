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
    since the permutation limited from 1 to n only

    msb logic for checking - f pi&x==0  it 

    `constraints low enough for o(n2) with optimizations

    so technically we got 2 queries per number from 1 to n

    which we can easily find using the bits like when the AND is 0 it means all bits from x is differ
    then we try for odd-spaced 1010... and if any bit true then setting that bit

    and since we know that totalxor ^ (1^2^3..n-2^n-1) gives us the missing xor


  */

    ll n;cin>>n;

    ll totxor=0;
    f(i,1,n+1) totxor ^= i;


    ll xor_p = 0;
    f(i,1,n){
        ll curr=0;

        for(int j=14;j>=0;j--){
            if((curr | (1ll << j)) > n)
                continue;


            cout << "? " << i << (1ll << j) << endl;
            ll res;cin>>res;

            if(res == 1){
                curr |= (1ll << j);
            }

        }

        xor_p ^= curr;

    }


    cout << "!"<<(totxor ^ xor_p) << endl;
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