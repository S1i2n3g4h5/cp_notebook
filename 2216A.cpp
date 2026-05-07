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
    moving from last to k+1 is optimal

    like moving k-1 to k 
    then k-2 to k-1 to k etc....
  */

    int n,k;cin>>n>>k;
    vll arr(k+1),b(n);
    f(i,1,k+1)cin>>arr[i];
    f(i,0,n)cin>>b[i];

    vll ops;
    bool chg=false;

    while(chg){
        chg=false;

        for(int target_lvl = k;target_lvl>=1;target_lvl--){
            f(i,0,n){
                if(b[i] == target_lvl){
                    int into = b[i] +1;

                    if(into == k+1 or count(all(b), into) < arr[into]){
                        b[i]++;

                        ops.pb(i+1);
                        chg=true;
                    }
                }
            }
        }
    }


    print(ops.size());
    for(auto x:ops)cout << x << " ";
    cout <<"\n";


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