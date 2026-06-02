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

    maximise the possibel distinct numbers!

    distributing duplicates to both heaps


  */

    ll n;cin>>n;
    // n = 2*n;
    vll arr(2*n);
    f(i,0,2*n)cin>>arr[i];


    map<ll,ll>frq;
    f(i,0,2*n){
        frq[arr[i]]++;
    }


    map<ll,vll>grp;
    f(i,0,2*n){
        grp[arr[i]].pb(i);
    }
    

    vll h1,h2,extra;

    int t=0;
    for(auto x:grp){
        auto idxs = x.second;

        if(idxs.size() >= 2){
            h1.pb(idxs[0]);
            h2.pb(idxs[1]);

            f(i,2,(ll)idxs.size()){
                extra.pb(idxs[i]);
            }
        }
        else{
            if(t==0){
                h1.pb(idxs[0]);
                t ^= 1;
            }
            else{
                h2.pb(idxs[0]);
                t ^= 1;
            }
        }

    }


    // print(h1.size(), h2.size(), extra.size());
    for(auto idx:extra){
        if(h1.size() < n){
            h1.pb(idx);
        }
        else
            h2.pb(idx);
    }


    vll ans(2*n,0);
    set<ll>s1,s2;
    for(auto idx:h1){
        ans[idx] = 1;
        s1.insert(arr[idx]);
    }
    for(auto idx:h2){
        ans[idx] = 2;
        s2.insert(arr[idx]);
    }



    print((ll)s1.size() * (ll)s2.size());

    for(auto x:ans){
        cout << x << " ";
    }
    cout << "\n";

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