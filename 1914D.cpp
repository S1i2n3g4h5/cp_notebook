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

vector<pair<int,int>> gettop(int n, vll arr){
    vector<pair<int,int>>v;
    f(i,0,n){
        v.push_back({arr[i], i});
    }

    sort(rall(v));
    return {v[0], v[1], v[2]};
}

void solve(){
  /*
    since optimized brute force can work
    instead of brute forcing all combinations

    since we got only 3 activities, we can just loop for 3x3x3
    like best 3 from each activities to loop and get combination which fits well

    the logic behind choosing 3 only is that
    even if 2 activities occuring on same day there is still space
    for choosing the best 3rd activity which always gives space to choose from
    similar to pigenhole theory...
  */

    int n;cin>>n;
    vll a(n), b(n), c(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];
    f(i,0,n)cin>>c[i];


    auto A = gettop(n, a);
    auto B = gettop(n, b);
    auto C = gettop(n, c);


    ll ans=0;
    for(auto i:A){
        for(auto j:B){
            for(auto k:C){
                if(i.second != j.second and i.second != k.second and j.second != k.second){
                    ans = max(ans, (ll)i.first + j.first + k.first);
                }
            }
        }
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