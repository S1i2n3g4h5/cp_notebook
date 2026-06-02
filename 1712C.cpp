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

    to solve this we can find the last positions of everything and then
    also check for the last index of each unique element occuring
    and then also checking for the most recent barrier happening from right to left

    to determin the most best index so that i=0 - barrierindex, we are required to make changes only into this zone

    and as while doing the changes we can just continue the expansion and manually continue doing that


  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    map<ll,ll>last_index;
    f(i,0,n){
        last_index[arr[i]] = i;
    }


    ll barrier = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            barrier = i;
            break;
        }
    }


    if(barrier == -1){
        print(0);
        return;
    }



    // expanding the barrier
    set<ll>unq;

    f(i,0,barrier+1){

        if(arr[i] !=  0){
            unq.insert(arr[i]);

            barrier = max(barrier, last_index[arr[i]]);
        }

    }


    print(unq.size());

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