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

    SO just requiring the prefix sums such that it forms a permuation
    need ot arrange the array permution vluaes uch t forms all kinds of remanders 0<=n-1

    obs1 -> total sum%2 ==0 (even) wont have the answers;

    array b=>  0 n-1 1 n-2 2 n-3 ...



  */

    ll n;cin>>n;

    if(n==1){
        print(1);
        return;
    }

    
    if((n)%2 == 1){
        print(-1);
        return;
    }



    ll lastb= 0;
    ll low=1, high=n-1; 

    
    cout << n << " ";
    f(i,1,n){

        int currb;
        if(i%2 ==0 ){
            currb = low++;
        }
        else{
            currb = high--;
        }

        int a = (currb - lastb+ n) % n;
        if(a == 0)
            a = n;

        cout << a << " ";
        lastb= currb;

    }

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