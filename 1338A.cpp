/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
    since each element cna be increased in any value from 0 to 2^T-1
    final goal is to make ai<=ai+1  (increasing order);


    and more clearly we sse,the T is just number of Bits required to represent the `need`
    that is how much more difference atleast required to make increasing;

  */

    int n;cin>>n;
    vll arr(n);
    bool already_sorted=1;
    f(i,0,n){
        cin>>arr[i];
        if(i>=1){
            already_sorted &= (arr[i-1] <= arr[i]);
        }
    }


    if(already_sorted){
        print(0);
        return;
    }


    ll mx_gap = 0;
    ll prev=arr[0];
    f(i,0,n){
        if(arr[i] < prev)
            mx_gap = max(mx_gap, prev - arr[i]);
        else    
            prev = arr[i];
    }




    ll T=0;
    while((1ll<<T) <= mx_gap)
        T++;


    print(T);

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