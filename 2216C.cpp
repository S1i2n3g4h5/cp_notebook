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
    constraints are also high, so loops wont have any chance to pass if simuated this process

    and the k input doesnt mattern here any, cuz we can always apply the operaiton by selecitng the whole array at each operations

    since only 2 choices for ops - p<q
        - arri mode p
        - (arri mod q ) mod p


    here initially i thought that just find min values for each arrayi and return the sum
    but its the wrong pitfall, cuz if we ake the k windw subaray and apply ops1 where we could have got min in maybe arr[i+1] throgh ops2

    this is the core problem and observation and solution as well
    cuz this tells we just need to iterate from each index for optimal arrayi

    ---

    so instead of choosing the whole arra which is wrong cuz here we trying to force single operation for all array which is wrong
    hence using the smallest k window array to choose from b,c mod and the rest can be easily chosen through the min possible stored inot the finalarray[i]

    this is the correct way to solve this
    

  */

    ll n,k,p,q;cin>>n>>k>>p>>q;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }

    vll b(n+1,0),c(n+1,0),finalarr(n+1,0);
    f(i,0,n){
        ll val1 = arr[i]%p;
        ll val2 = (arr[i]%q)%p;

        b[i+1] = b[i] + val1;
        c[i+1] = c[i] + val2;

        finalarr[i+1] = finalarr[i] + min(val1,val2);
    }


    ll tot = finalarr[n];
    ll mn_sm = -1;
    f(i,0,n-k+1){
        int l=i+1;
        int r=i+k;

        ll outside_sum = tot - (finalarr[r] - finalarr[l-1]);

        ll inside_sum = min(b[r] - b[l-1], c[r] - c[l-1]);

        ll curr = outside_sum + inside_sum;
        if(mn_sm == -1 or mn_sm > curr){
            mn_sm = curr;
        }

    }


    // print(min(b[n], c[n]));
    print(mn_sm);

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