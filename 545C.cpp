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
    first always trying to fall tree to left then right then if not possible then keep it standing
    as we know that falling to right hinders the next trees potential to fall left so this right operation is costly


  */

    int n;cin>>n;
    vector<pair<ll,ll>>arr(n);
    f(i,0,n){
        ll x,y;cin>>x>>y;
        arr[i] = {x,y};
    }


    if(n==1){
        print(1);
        return;
    }


    // 1st tree(left fall)    +   last tree(right fall)
    ll ans=2;
    ll last_pos=arr[0].first;

    f(i,1,n-1){
        
        if(arr[i].first - arr[i].second > last_pos){
            // left fall?
            
            last_pos = arr[i].first;
            ans++;
        }
        else if(arr[i].first + arr[i].second < arr[i+1].first){
            // right fall?
            
            last_pos = arr[i].first + arr[i].second;
            ans++;
        }
        else{
            last_pos = arr[i].first;
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