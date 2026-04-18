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
    2n+1 elems
        -> twice repeating
        -> 1 element repeating thrice

    max 66 queires

    constriants  n -> 1e3  (small enough)
        -> roughly 15 comps (fool brute)


    
    we using 3 binar searhc to search those 3 indexes properly 

  */

    ll n;cin>>n;
    ll tot = 2*n+1;


    
    auto askquery = [&](vll v){
        if(v.empty()) 
            return 0;
        
        cout << "? " << v.size();
        f(i,0,v.size())
            cout << " " << v[i];
        cout << endl;


        int res;cin >> res;
        if(res == -1) exit(0);

        return res;
    };


    //______ ans3
    ll low=1, high=tot;
    ll ans3 = tot;
    
    while(low<=high){
        ll mid = low + (high - low)/2;
        
        vll curr;
        f(i,1,mid+1){
            curr.pb(i);
        }

        ll res = askquery(curr);
        
        if(res %2 != mid%2){
            ans3 = mid;
            high = mid-1;
        }
        else{
            
            low = mid+1;
        }    
        
    }
    
    
    //______ ans1
    low = 1, high = ans3 - 1;
    ll ans1 = 1;
    while(low<=high){
        ll mid = low + (high - low)/2;
        
        vll curr;
        f(i,1,mid+1) curr.pb(i);

        vll withans3 = curr;
        withans3.pb(ans3);
        
        if(askquery(withans3) <= askquery(curr)){
            ans1 = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }

    }
        
        
    //______ ans2
    low = ans1+1,high=ans3-1;
    ll ans2=ans1+1;

    while(low <= high){
        ll mid = low + (high - low)/2;
        
        vll curr;
        f(i,1,mid+1)curr.pb(i);

        vll withans3 = curr;
        withans3.pb(ans3);

        if(askquery(withans3) == askquery(curr)){
            ans2 = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }


    cout << "! "<< ans1 << " " << ans2 << " " << ans3 << endl;
    

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