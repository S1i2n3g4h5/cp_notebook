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

  */

    ll k,q;cin>>k>>q;
    vector<pair<ll,ll>>arr(q);
    f(i,0,q)cin>>arr[i].first>>arr[i].second;



    // ####################################3
    auto nCr = [](auto n, auto r){
        if (r<0  or  r>n) 
        return 0ll;
        
        r = min(r, n-r);
        
        ll res = 1;
        f(i,1,r+1){
            res = res * (n - r + i)/i;
        }
        return res;
    };
    // f(i,1,5+1){
    //         f(j,1,5+1){
    //         cout << nCr((ll)i,(ll)j)%k << " ";
    //     }
    //     cout <<"\n";
    // }
    // ####################################3
    // f(l,0,q){
    //     int ans=0;
    //     int n = arr[l].first;
    //     int m = arr[l].second;

    //     f(i,1,n+1){
    //         f(j,1,min(i,m)+1){
    //             // print(i,j, "  -  ", nCr(i,j));

    //             if(nCr(i,j)%k == 0){
    //                 ans++;
    //             }
    //         }
    //     }

    //     print(ans);
    // }
    // ####################################3
    // int n=5,m=5;
    

    // vector<vll>mat(1005,vll(1005,0));
    // f(i,1,1005){
    //     f(j,1,1005){
    //         // cout << nCr((ll)i,(ll)j)%k << " ";
    //         mat[i][j] = (j<=i and nCr((ll)i, (ll)j) % k == 0 ? 1 : 0);
    //     }
    // }
    // vector<vll> pf(1001,vll(1001,0));
    // f(i,1,1001){
    //     f(j,1,1001){

    //         ll prev = pf[i-1][j-1] + pf[i-1][j] + pf[i][j-1];
    //         ll curr = (j<=i and mat[i][j] == 0 ? 1 : 0);
            
    //         pf[i][j] = prev + curr;
            
    //         // if(i<=n and j<=m){
    //         //     print(pf[i][j-1]);    
    //         //     print(pf[i-1][j]) ;   
    //         //     print(pf[i-1][j-1]) ;   
    //         // }
    //     }
    //     // if(i<=n ){
    //     //     cout <<"\n";
    //     // }
    // }

    
    
    vector<vll>pascal_table(1005, vll(1005, 0));
    for (int i = 0; i <= 1000; i++) {
        pascal_table[i][0] = 1 % k;
        for (int j = 1; j <= i; j++) {
            pascal_table[i][j] = (pascal_table[i - 1][j - 1] + pascal_table[i - 1][j]) % k;
        }
    }
    vector<vll> prefix_sum(1001,vll(1001,0));
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            int current_match = (j <= i && pascal_table[i][j] == 0) ? 1 : 0;
            
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + current_match;
        }
    }


    // mat[1][1] = 1;
    // f(i,1,n+1){
    //     f(j,1,min(i,m)+1){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout <<"----"<<"\n";
    // f(i,1,n+1){
    //     f(j,1,min(i,m)+1){
    //         cout << pascal_table[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    


    // queries..
    f(i,0,q){
        ll n = arr[i].first;
        ll m = arr[i].second;

        print(prefix_sum[n][m]);
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