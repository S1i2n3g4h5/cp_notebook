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


const bool multipleTestCases = 0; 

void solve(){
  /*
    given some a,b  whch we calc gcd

    needs to find the nearest valies gcd of a,b suhc that l<=gcd<=r
    else -1

    shortcut-> any number that divides a and b, must be a divisor of gcd(a,b);


    so instead of scanning ranges one by one, we just get all the diisors form the gcd(a,b)
    an djust check if there is any numer common between the diiosr meeting the range criteria
        low <= divisor <= high

    ------

     according to the number theory its not imporant for just gor 2g or 3g.... to be divisble by a,b
but instead that any diivsor of gcd(a,b) is also divisor of a,b
whch puts us through valid answer


  */

    ll a,b;cin>>a>>b;
    ll q;cin>>q;

    ll g = __gcd(a,b);

    vll divs;
    for(ll i=1;i*i <= g;i++){
        if(g%i == 0){
            divs.pb(i);
            if(i*i != g)divs.pb(g/i);
        }
    }

    sort(all(divs));


    while(q--){
        ll l,h;cin>>l>>h;

        auto it = upper_bound(all(divs), h);

        if(it == divs.begin()){
            print(-1);
        }
        else{
            it = prev(it);
            if(*it >= l){
                print(*it);

            }
            else{
                print(-1);

            }

        }

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