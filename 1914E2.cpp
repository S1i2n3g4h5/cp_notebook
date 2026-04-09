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

    so main formula is   ai-bi final one

    which alice try to maximize but bob tris to minimize
     
    and its kind of greedy implementation games

  */

    int n;cin>>n;
    vector<int> a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    struct Color{
        int a,b;
        ll sum;
    };
    auto compare_color = [&](Color& x, Color& y){
        return x.sum > y.sum;
    };


    vector<Color>colors(n);
    f(i,0,n)
        colors[i] = {a[i], b[i], (ll)(a[i] + b[i])};


    sort(all(colors), compare_color);


    ll score = 0;
    f(i,0,n){
        if(i%2 == 0){
            score += (colors[i].a - 1);
        }
        else{
            score -= (colors[i].b - 1);
        }
    }


    print(score);


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