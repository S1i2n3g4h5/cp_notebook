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
    odd lengt strings are good for us cuz tehy got 1 extra character at disposal which can be anywher

    also not that if we got some string 2 we can always do spaping as many time as required to make the 
    0,1 at right place. 
    
    the question aks to make all strings palindom.

    so instead of going to check eahc, just checking the invariant here
    ?

  */

    int n;cin>>n;
    vector<string>arr(n);
    f(i,0,n)cin>>arr[i];

    
    int odd=0,evengood=0,evenbad=0;
    f(i,0,n){
        
        if(arr[i].size()%2 == 1)
            odd++;
        else{
            int zerocnt = count(all(arr[i]), '0');
            if(zerocnt%2 ==0)
                evengood++;
            else 
                evenbad++;
        }

    }


    if(odd ==0 and evenbad%2 ==1){
        print(n-1);
    }
    else{
        print(n);
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