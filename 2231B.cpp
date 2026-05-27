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
    cn be divided into 2 teams, one whichstays the same and another one which needs to be added +k into


  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    vector<bool>isteamA(n, false);
    ll currmx = -1;
    vll teamB;
    ll min_k = 0;
    f(i,0,n){
        if(arr[i] >= currmx){
            isteamA[i] = true;
            currmx = arr[i];

        }
        else{
            teamB.pb(arr[i]);
            min_k = max(min_k, currmx - arr[i]);
        }
    }


    f(i,1,teamB.size()){
        if(teamB[i] < teamB[i-1]){
            print("NO");
            
            return;
        }
    }


    ll max_k = 2e9, nextteama = 2e9;
    for(int i=n-1;i>=0;i--){
        if(isteamA[i]){
            nextteama = arr[i];

        }
        else{
            max_k = max(max_k, nextteama - arr[i]);
        }
    }


    if(min_k <= max_k)print("YES");
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