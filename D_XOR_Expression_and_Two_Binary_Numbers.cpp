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
    so there is a pattern of 3 groups gettgin repeated
    for odd case, just the last one getting dropped, but for the even n, the condition is being followed

    let given a,b then the group is like-> a,b,a^b
    just count for these, and the rest is done, coutning principle only


  */

  ll n,k;cin>>n>>k;
  string a,b;cin>>a>>b;

  string xor_string(n,'0');
  f(i,0,n){
    if(a[i]!=b[i])
      xor_string[i] = '1';
  }


  ll a_0=0,a_1=0;
  ll b_0=0,b_1=0;
  ll xor_0=0,xor_1=0;

  f(i,0,n){
    if(a[i] == '0'){
      a_0++;
    }
    else{
      a_1++;
    }

    if(b[i] == '0'){
      b_0++;
    }
    else{
      b_1++;
    }

    if(xor_string[i] == '0'){
      xor_0++;
    }
    else{
      xor_1++;
    }
  }


  k = (1ll << k) + 1;

  ll fullcycle = k/3;
  ll remcycle = (k%3 == 0 ? 0 : 1);

  // cout << "fullcycle - " << fullcycle << "\n" << "remcycle - " << remcycle << "\n" << " k- "<<k<<"\n";
  // cout << "a - " << (a_0*a_1)  << "\n";
  // cout << "b - " << (b_0*b_1)   << "\n";
  // cout << "a^b - " << (xor_0*xor_1) << "\n";

  ll fullcyclesum=0, remcyclesum=0;
  fullcyclesum = fullcycle * ((a_0*a_1) + (b_0*b_1) + (xor_0*xor_1));
  remcyclesum = remcycle * ((a_0*a_1) + (b_0*b_1));

  cout << fullcyclesum + remcyclesum << "\n";

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