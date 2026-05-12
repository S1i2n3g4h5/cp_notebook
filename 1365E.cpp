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
    since due to the constraint - max(1,|s|-2)
    its really good tradeoff and cosntraint

    cuz its not alwa the case that more elemtns means maximium sum or bit

    but here due to thte constrain given we cna apply for 3 length elemts
    where atleast 1 will have that 1 bit set

    

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    if(n==1){
        print(arr[0]);
        return;
    }
    else if(n==2){
        print(arr[0] | arr[1]);
        return;
    }
    

    ll mx=0;
    f(i,0,n){
        f(j,i+1,n){
            f(k,j+1,n){
                ll curr = arr[i]|arr[j]|arr[k];

                mx = max(curr, mx);
            }
        }
    }


    print(mx);

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