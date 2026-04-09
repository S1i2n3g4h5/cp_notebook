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
    need to consume the least 1s possible

    just need to find the min ones avaiale in any 2x2 sqaure so from this we can easily find out,
    -> having 4 ones then cost - 2
    -> having 3 ones then cost - 1
    -> having <=2 ones then cost is just whatever provided

  */

    int n,m;cin>>n>>m;

    ll ones=0;
    vector<string>arr(n);
    f(i,0,n){
        cin>>arr[i];
        ones += count(all(arr[i]), '1');
    }

    

    if(ones == 0){
        print(0);
        return;
    }


    ll min_ones = 4;
    f(i,0,n-1){
        f(j,0,m-1){
            ll cnt = (arr[i][j] - '0')  + (arr[i+1][j] -'0') + (arr[i][j+1]-'0') + (arr[i+1][j+1] - '0');

            min_ones = min(cnt, min_ones);
        }
    }



    if(min_ones == 4){
        print(ones - 2);
    }
    else if(min_ones == 3){
        print(ones - 1);
    }
    else {
        print(ones);
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