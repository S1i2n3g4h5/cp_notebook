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
    brute forcing 
  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    ll ans = n;
    ll first_seg_sum = 0;
    f(i,0,n){

        first_seg_sum += arr[i];
        ll curr_target = first_seg_sum;
        ll max_split_len = i+1;


        ll tmpsm = 0;
        ll tmpln = 0;
        bool possible = true;

        f(j,i+1,n){
            tmpsm += arr[j];
            tmpln++;

            if(tmpsm == curr_target){
                max_split_len = max(max_split_len, tmpln);

                tmpsm = 0;
                tmpln = 0;
            }
            else if(tmpsm > curr_target){
                possible = false;
                break;
            }
        }


        if(tmpsm > 0)
            possible = false;

        
        if(possible){
            ans = min(ans, max_split_len);
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