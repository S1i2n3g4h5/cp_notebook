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


const bool multipleTestCases = 0; 

void solve(){
  /*
    so the rope divide like this (0,1) (1,2) (2,3)....(99,100);

    need to find the block untouched by otheers. 

    note-> evne the closed end or closed opens cna be used too :)   like [1,2] used by somene os alex uses[0,1];
  */

    int n;cin>>n;
    vector<pair<ll,ll>> arr(n);
    f(i,0,n){
        int l,r;cin>>l>>r;
        arr[i] = {l,r};
    }

    int l1 = arr[0].first;
    int r1 = arr[0].second;

    int ans=0;
    f(i,l1,r1){
        bool blocked= false;

        f(j,1,n){
            if(i >= arr[j].first and i<arr[j].second){
                blocked=true;
                break;
            }
        }

        if(!blocked){
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