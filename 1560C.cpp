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
    grid infinite table like 
    layer 1 = 1
    layer 2 = 2,3,4
    layer 3 = 5,6,7,8,9
    and so on     getting +2 added...


    observation - each layer ends at   x^2  
      like layer 1 ends at 1^2
           layer 2 ends at 2^2
           layer 3 ends at 3^3


    total elemsn in eahc layer is 2x - 1
    and corner of each layer x is  (x,x);




  */

  ll k;cin>>k;
    

  // layer root
  ll x = sqrt(k);
  if(x*x < k)
    x++;


  ll m = x*x - x + 1;

  ll row,col;

  if(k == m){
    row = x;
    col = x;
  }
  else if(k < m){
    col = x;
    row = k - (x-1)*(x-1);
  }
  else{
    row = x;
    col = x*x -k -1;
  }


  print(row, col);

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

