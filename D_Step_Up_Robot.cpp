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
    brute forcing the wats to reaaced will result tle

    hecnc doing dp

    trying with pull dp, cuz intuitive,
    as it eans that if im on some step i, asking is ther any way i could have landed here just now?
    that is why the state is   (i - arr)


    this solutino also psibel thorugh push dp aswell

  */

    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];
    int m;cin>>m;
    
    vector<bool>trap(100001,false);
    f(i,0,m){
        int x;cin>>x;
        trap[x] = true;
    }

    int x;cin>>x;

    vll dp(x+1,false);
    dp[0] = 1;



    // ##################################################
    //       P U S H    D P  
    // ##################################################
    f(i,0,x+1){
        if(!dp[i])continue;

        for(auto jump : a){
            int next_step = i+jump;

            if(next_step <= x and !trap[next_step]){
                dp[next_step] = true;
            }
        }

    }    
    
    
    
    // ##################################################
    //       P U L L   D P   
    // ##################################################
    // f(i,1,x+1){
    //     if(trap[i]) continue;

    //     for(auto jump:a){
    //         if(i-jump >=0 and dp[i-jump]){
    //             dp[i] = 1;
                
    //             break;
    //         }
    //     }

    // }




    if(dp[x]) print("Yes");
    else print("No");

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