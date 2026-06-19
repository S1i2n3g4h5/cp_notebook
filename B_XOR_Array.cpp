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
    xor gets zeo when the bits same, hence-
    f(x,y) = 0 when py = px-1
    and vice versa for f(x,y) != 0
    

    ____________-------------____________------------____________-----------
    
    most important rule of xor is A ^ B = C then A^C = B

    so as the problem require from l to the combned or of that window to be 0, 
    this means we need (l-1) from where the window started, cuz then only the running
    total of end of windo it meas abslutely nothign changed... thus xor combined(prefix) = 0

    -> Pi meaning prefix xor till curent index i

    XOR(from l to r) = P(l-1) xor P(r)
    
    Pr -> containt all elems for 1 to r;
    Pl-1 -> contains all elemn form 1 to l-1


    so since we stand at p=r,
    we want the bucke to hold vlue of r-1 and next bucket to equal l-1
    then,
    fr = (r-1) ^ (l-1)

    for the p=r+1 (reset point)

  */
  

    ll n,l,r;cin>>n>>l>>r;

    vll p(n+1);
    f(i,0,n+1){
      p[i] = i;
    }

    
    p[r] = p[l-1];
    f(i,1,n+1){
      cout << (p[i] ^ p[i-1]) << " \n"[i==n];
    }


    // cout << "\n";


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