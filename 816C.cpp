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
    basic implementation only

    we can fix r1, and check what exactly thesubtraction requried
    from row or column side.
    -> since gij = ri + cj



  */

    ll n,m;cin>>n>>m;
    vector<vll> mat(n, vll(m, 0));
    f(i,0,n){
        f(j,0,m){
            cin>>mat[i][j];
        }
    }

    
    vector<string>moves;


    auto strip_row = [&](){
        f(i,0,n){
            ll mn = 1e9;
            f(j,0,m){
                mn = min(mn, mat[i][j]);
            }
        
            if(mn > 0){
                f(j,0,m){
                    mat[i][j] -= mn;
                }
                f(k,0,mn){
                    moves.pb("row " + to_string(i+1));
                }
            }

        }
    };
    auto strip_col = [&](){
        f(j,0,m){
            ll mn = 1e9;
            f(i,0,n){
                mn = min(mn, mat[i][j]);
            }

            if(mn > 0){
                f(i,0,n){
                    mat[i][j] -= mn;
                }
                f(k,0,mn){
                    moves.pb("col " + to_string(j+1));
                }
            }
        }
    };
    

    // greedy removing
    if(n<=m){
        strip_row();
        strip_col();
    }
    else{
        strip_col();
        strip_row();
    }

    
    // validation?
    f(i,0,n){
        f(j,0,m){
            if(mat[i][j] > 0){
                // print("-1");
                cout << -1 << "\n";
                return;
            }
        }
    }


    cout << moves.size() << "\n";
    for(auto x:moves){
        // print(x);
        cout << x << "\n";
    }
    // cout <<"\n";

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