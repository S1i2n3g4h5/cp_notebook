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
    onyl characters are 0 and 1 for sorting
    so if we know that the index of last zeor (zn) and the index of first one (onei)
    then if zn<on then no sorting requreid as its already sorted


    doing brute force simulation will result into TLE
    but simulation will be done

    precomputation can bwe reuqired to claualte all the zero one possitions 

  */

    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<pll> arr(m);
    f(i,0,m){
        cin>>arr[i].first>>arr[i].second;
    }


    vll next_one(n), prev_zero(n);

    int last_one=n;
    for(int i=n-1;i>=0;i--){
        if(s[i] =='1')last_one = i;
        next_one[i] = last_one;
    }

    int last_zero=-1;
    f(i,0,n){
        if(s[i] == '0') last_zero=i;
        prev_zero[i] = last_zero;
    }


    set<pll>ans;
    f(i,0,m){
        ll l = arr[i].first - 1;
        ll r = arr[i].second - 1;

        ll st = next_one[l];
        ll ed = prev_zero[r];

        if(st >= ed){
            ans.insert({-1,-1});
        }
        else{
            ans.insert({st,ed});
        }

    }


    print(ans.size());

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