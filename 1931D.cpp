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
    ai+aj  divisible by x   and 
    ai-aj divisible by y

        total beautiful pairs?

    brute force fails directly so instead of solving for the numbers
    trying for the reaminders

    like  -  (ai-aj)%x ==0
        hence ai%x - aj%x = 0
              ai%x = (x + (aj%x))%x

    for second -
        (ai - aj)%y ==0
        ai%y  = aj%y

    
    so for ai we calcl both x,y
    and check if any pairs mathcing there then its the answer

    

  */

    ll n,x,y;cin>>n>>x>>y;
    vll a(n);
    f(i,0,n)cin>>a[i];


    map<pair<ll,ll>,ll>count;
    ll ans=0;

    for(auto v:a){
        ll remx = v%x;
        ll remy = v%y;

        ll targetx = (x - remx)%x;
        ll targety = (remy);

        if(count.count({targetx, targety})){
            ans += count[{targetx, targety}];
        }

        count[{remx, remy}]++;

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