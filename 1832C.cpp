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
    since the final contrast is ike frist elem - end elem

    hence to find the min length subsequence b array
    we can delete the values that dont contribute
    like if ai-1 < ai < ai+1
        this ai is useless cuz iits not contributing hence rmeoving this
    and only caring about those which make big difference

    cuz example - 
        1. 0, 10, 0
            here total distnce is 10+10 = 20
            ut if we remove 10 then its 0, this means 10 is important
        2. 0, 5, 10
            total distancec=10
            if we delte 5 its still 10 hence 5 useless



  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    arr.erase(unique(all(arr)), arr.end());


    if(arr.size() <= 1){
        print(1);
        return;
    }


    int ans=2;
    f(i,1,arr.size()-1){
        if((arr[i] > arr[i-1] and arr[i] > arr[i+1]) or (arr[i] < arr[i-1] and arr[i] < arr[i+1])){
            ans++;
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