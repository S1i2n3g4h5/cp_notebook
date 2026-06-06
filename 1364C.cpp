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


const bool multipleTestCases = 0; 

void solve(){
  /*

    so we just ned to fill inthe numbers and check if its ther eor not
    like bi = ai-1  cuz we know if we got ai-1 from 0 mex then ai is the next MEX

    similarly when we get empty spaces like 1 1 3
    we need to fill 1 at the 3rd possitions to mathc the output
    so need to tae care of these empty possition more carefully

    Also, watch the constraits properrly so we get to know
    that we dont need to check for -1 condition
    
    

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    vector<bool>present(1e6+5,false);
    for(auto x:arr)
        present[x] = true;


    vll b(n, -1);
    
    f(i,1,n){
        
        if(arr[i] != arr[i-1])
        b[i] = arr[i-1];
    }
    
    
    // filling empty slots
    ll current_unused = 0;
    f(i,0,n){
        if(b[i] == -1){
            while(present[current_unused]){
                current_unused++;
            }

            b[i] = current_unused;
            present[current_unused] = true;
        }
    }


    f(i,0,n)
        cout << b[i] << " ";
    cout << "\n";
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