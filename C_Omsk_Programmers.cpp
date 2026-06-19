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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
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

    the min can be achieved at some values v by dividing i times, and j times 
    ; then adding 1s to the smallers of the a,b to get equal vlaue;

    adding 1 before division doesnt makes sense...
    cuz, (a+k)/x <= (a/x) + k
    <dry ran few stuf..>

    due to mangaebel reslts to loop over to find the possible stuff...
    its possible within constraints limits;    

  */

    ll a,b,x;cin>>a>>b>>x;
    
    
    if(a==b){
        cout << "0\n";
        return;
    }
    
    
    vll va,vb;
    ll curra = a;
    while(true){
        va.push_back(curra);
        if(curra == 0){
            break;
        }

        curra /= x;
        
    }

    ll currb = b;
    while(true){
        vb.push_back(currb);
        if(currb == 0){
            break;
        }

        currb /= x;
        
    }


    ll ans = -1;
    f(i,0,va.size()){
        f(j,0,vb.size()){

            ll diff = abs(va[i] - vb[j]);

            ll total = i + j + diff;

            if(ans == -1 or total < ans){
                ans = total;
            }

            // cout << diff << "\n";
        }
    }


    cout << ans<<"\n";

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