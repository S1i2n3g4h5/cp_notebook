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
    since inital answer consists of ubarray of 1 and 2 bydefaultt

    simplified condiitons- 
        ai - aj + aj-ak = ai-ak

    on observing we find that aj must be between [ai,ak]
    hence the only possibel subaray not possible are those that are increasing or decreasing contiuously

    need to check all triplets till subarray 4 only


    something like `erdos szekeres theorem` states that for exaple any subsequence of length 5 is guaranteed to contain 
    atleast 1 monotonic subsequence of length 3

    ----

    since we are required to find all those good airs which dont for this condition dpr = dpq+dqr
    we find that for 3 3 subsequence pairs, any length of chosen elemnts >= 5 will contains all bad pairs hence all of them condtributing 0

    and thus we only looking for the lengths of subarrays - [1,4]
    but since the conditon imposed is i<j<k, which will defiantaly reuslt into monotonic increasing/decreasing which is always bad for us



  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    auto is_good = [&](vll&arr, int i, int j){
        // if(j-i+1 < 3)
        //     return true;

        f(L,i,j+1){
            f(R,L+1,j+1){
                f(K,R+1,j+1){

                    bool incr = (arr[L] <= arr[R] and arr[R] <= arr[K]);
                    bool decr = (arr[L] >= arr[R] and arr[R] >= arr[K]);
                    
                    if(incr or decr){
                        return false;
                    }
                }
            }
        }

        return true;

    };


    ll ans = n + (n-1);
    // ll ans =0 ;

    f(i,0,n){
        for(int step=3;step<=4 and step+i <=n;step++){

            if(is_good(arr, i, i+step-1)){
                ans++;
            }

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