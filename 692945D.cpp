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


const bool multipleTestCases = 0; 

void solve(){
  /*

  */

    ll n;cin>>n;
    vector<pll>arr(n);
    f(i,0,n)cin>>arr[i].first>>arr[i].second;
    ll q;cin>>q;
    vector<pll>queries(q);
    f(i,0,q){
        cin>>queries[i].first>>queries[i].second;
    }
    
    
    vll nxtC(n,0),nxtE(n,0);
    
    nxtC[n-1] = n;
    nxtE[n-1] = n;


    for(int i=n-2;i>=0;i--){
        if(arr[i].first == arr[i+1].first)
            nxtC[i] = nxtC[i+1];
        else{
            nxtC[i] = i+1;
        }

        if(arr[i].second == arr[i+1].second)
            nxtE[i] = nxtE[i+1];
        else    
            nxtE[i] = i+1;
    }


    // f(i,0,n){
    //     cout << nxtC[i] << ",";
    // }
    // cout <<"\n";
    // f(i,0,n){
    //     cout << nxtE[i] << ",";
    // }
    // cout <<"\n";


    for(auto x:queries){
        ll l = x.first -1;
        ll r = x.second -1;

        int i=nxtC[l];
        int j=nxtE[l];


        if(i>r or j>r){
            cout << ("MARIO IS SAFE") << "\n";
        }
        else{   
            cout << ("MARIO IS NOT SAFE") << "\n";

            // print(i+1,j+1);

    
            bool l1i=(arr[l].first != arr[i].first  and arr[l].second != arr[i].second); 
            bool l1j=(arr[l].first != arr[j].first and arr[l].second != arr[j].second);

            if(l1i){
                // print(l+1, i+1);
                cout <<i+1<< " " << l+1<<"\n";
            }
            else if(l1j){
                // print(l+1, j+1);
                cout <<j+1 << " " << l+1<<"\n";
            }
            else{
                // print(i+1, j+1);
                cout <<i+1 << " " << j+1<<"\n";
                
            }

        }

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
