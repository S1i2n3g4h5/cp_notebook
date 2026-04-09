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
    greedy problem
    k-step approach to sole this..
        so round1 affects round 1+k, round 1+2k ...
        so round2 affects round 2+k, round 2+2k ...

    optimal scores -
        rock < paper
        scissor < rock
        paper < scissor

  */

    ll n,k;cin>>n>>k;
    ll r,s,p;cin>>r>>s>>p;
    string t;cin>>t;

    ll ans=0;
    vector<char>myhands(n);

    f(i,0,n){

        char machine = t[i];
        char win_hand;
        ll points=0;

        if(machine == 'r'){
            win_hand = 'p';
            points = p;
        }
        else if(machine == 's'){
            win_hand = 'r';
            points = r;    
        }
        else{
            win_hand = 's';
            points = s;
        }


        if(i< k or myhands[i-k]!= win_hand){
            ans += points;
            myhands[i] = win_hand;
        }
        else{
            myhands[i] = '.';
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