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

    since (x+k) + (y+k) = (x+k) ^ (y+k)

    we related this with addition and xor relation -
        (a+b) = a^b + 2(a & b);

    relating to this we find that a&b == 0

    =====

    case1-> x=y;
    then x+k=y+k for anyk>=0...
    since x>=1, x+k always positive.
    thus (x+k) & (x+k) = x+k & 0
    which not mathcing wiht equation hence no oslutinos exists.


    case2-> y>x;


  */

    ll x,y;cin>>x>>y;


    if(x==y){
        print(-1);
        return;
    }


    if(x>y)
        swap(x,y);

    ll p=0;
    while((1ll<<(p)) < y){
        p++;

    }

    // print((1ll<<p), y);

    print((1ll<<p) - y);

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