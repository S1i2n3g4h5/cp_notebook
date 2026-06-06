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

    if x=1, mex(0,1) = 2;
    if x>1, mex(0,x) = 1;
    if merge 2 zeores = mex(0,0) = 1;

    so any operation involving atleast one 0 will never result into 0


  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }


    vector<pll>ops;


    while(true){

        int zero_idx = -1;

        f(i,0,arr.size()){
            if(arr[i] == 0){
                zero_idx = i;
                break;
            }
        }

        if(zero_idx == -1)
            break;


        if(zero_idx == arr.size()-1){
            int l = zero_idx;
            int r = zero_idx + 1;


            ops.pb({l,r});


            int val1 = arr[zero_idx - 1];
            int val2 = arr[zero_idx];
            int mex = (val1 == 1 or val2 == 1) ? ((val1 == 2 or val2 == 2) ? 3 : 2) : 1;

            arr[zero_idx-1] = mex;
            arr.pop_back();

        }
        else{
            int l = zero_idx+1;
            int r = zero_idx+2;

            ops.pb({l,r});

            int val1 = arr[zero_idx];
            int val2 = arr[zero_idx+1];

            int mex = 1;
            if(val1 == 1 or val2 == 1){
                mex = 2;
            }

            arr[zero_idx] = mex;
            arr.erase(arr.begin() + zero_idx + 1);

        }
    }


    if(arr.size()>1){
        ops.pb({1,arr.size()});
    }
    

    print(ops.size());
    for(auto op:ops){
        print(op.first, op.second);
    }

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