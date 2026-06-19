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


const bool multipleTestCases = 1; 

void solve(){
  /*
    chosen elemnt must be increase and within the range of k;
    
    main constrain -
        0 <= y - x <= k;
    

  */

    ll n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    sort(all(arr));

    bool possible= false;
    for(int i=0;i<n;){
        ll m=0;

        bool evenf=false;
        int j =i;

        while(j<n){

            ll start = j;
            while(j<n and arr[j] == arr[start]){
                j++;
            }

            m++;

            if((j - start)%2 == 0){
                evenf = true;
            }


            // chk next distinct val belonging to same grp?
            if(j<n and arr[j]-arr[j-1] <= k){
                // continue , uz within gap limit
            }
            else{
                break;
            }

        }

        if(m>1 or evenf){
            possible = true;

            break;

        }


        i = j;
    }


    if(possible)
        cout << "YES\n";
    else
        cout << "NO\n";

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
