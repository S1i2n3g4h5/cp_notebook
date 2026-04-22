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
    so if we set ai=bi+1 hten postion i match if bi+1=bi
    similarly if we set bi=ai+1 then osition i is math if ai+1=ai

    single opeeration - to reomve complete ai,bi at index i
        with this we connect i-1  index with   i+1

    


  */

    ll n;cin>>n;
    vll a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    ll direct_match = 0;
    f(i,0,n){
        if(a[i] == b[i])
            direct_match++;
    }


    ll indirect_match = 0;
    f(i,0,n-1){
        ll curr = 0;

        
        // current already best?
        if(a[i] == b[i])
            curr--;


        // ai+1 == bi  or bi+1 = ai
        if(i+1 < n){
            if(a[i+1] == b[i]){
                indirect_match = max(indirect_match, curr + 1);
            }
            
            if(b[i+1] == a[i]){
                indirect_match = max(indirect_match, curr + 1);
            }
        }


        // removal? 
        if(i+1<n and i>0){
            if(a[i+1] == b[i-1]){
                indirect_match = max(indirect_match, curr + 1);
            }

            if(a[i-1] == b[i+1]){
                indirect_match = max(indirect_match, curr + 1);
            }
        }


        indirect_match = max(indirect_match, curr);

    }


    print(indirect_match + direct_match);

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
