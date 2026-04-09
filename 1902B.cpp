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
    to maximize rest and earning atleast P points in fewest possible study days

    3 types of points - 
        best day - l + 2t
        good day - l + t
        basic day- l


    since tasks unlocking on 1 8 15 ... is ap series

    total task T = (n-1)/7 + 1
    maximum best days - Dbest = T/2;
    remaining tasks (if t odd) Dgood = T (mod 2)



  */

    ll n,p,l,t;cin>>n>>p>>l>>t;

    ll total_tasks = (n-1)/7 +1;
    ll double_task = total_tasks /2;
    ll double_points =double_task * (l + 2*t);


    ll day_study=0;
    if(p <= double_points){
        day_study = (p + (l+ 2*t) -1) / (l + 2*t);
        p =0;
    }
    else{

        day_study += double_task;
        p -= double_points;

        if(total_tasks%2 == 1){
            day_study ++;
            p -= (l+t);
        }

        if(p>0){
            day_study += (p + l- 1) / (l);
        }

    }


    print(n - day_study);


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