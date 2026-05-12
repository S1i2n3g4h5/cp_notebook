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

bool check(int idx, int n, vll&arr){
    vll b;
    f(i,0,n){
        if(i!=idx){
            b.pb(arr[i]);
        }
    }


    int last_gcd=0;
    f(i,0,n-2){
        int curr = __gcd(b[i], b[i+1]);

        if(curr < last_gcd)
            return false;

        last_gcd = curr;
    }

    return true;

}


void solve(){
  /*

  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    int idx=-1;
    f(i,0,n-2){
        if(__gcd(arr[i], arr[i+1]) > __gcd(arr[i+1],arr[i+2])){
            idx=i;
            break;
        }
    }


    if(idx==-1){
        print("YES");
        return;
    }


    if(check(idx,n,arr) or check(idx+1,n,arr) or check(idx+2,n,arr)){
        print("YES");
    }
    else
        print("NO");

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