/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 


ll take_ceil(ll a,ll b){
    return (a+b-1)/b;
}

void solve(){
  /*


  */

    int n;cin>>n;
    struct Jedi{
        int id, min_v, mid_v, max_v;
    };  

    vector<Jedi>jedis(n);
    int m1=-1,m2=-1;
    int M1=-1,M2=-1;

    f(i,0,n){
        vector<int> arr(3);cin>>arr[0]>>arr[1]>>arr[2];
        sort(all(arr));
        jedis[i] = {i+1, arr[0], arr[1], arr[2]};
    
            
        if(arr[0] > m1){
            m2 = m1;
            m1 = arr[0];
        } 
        else if(arr[0] > m2){
            m2 = arr[0];
        }
            
        if(arr[1] > M1){
            M2 = M1;
            M1 = arr[1];
        } 
        else if(arr[1] > M2){
            M2 = arr[1];
            }
    }


        
    vll winners;
    f(i,0,n){
        int target_min = (jedis[i].min_v == m1) ? m2:m1;
        int target_mid = (jedis[i].mid_v == M1) ? M2:M1;
            
        if(jedis[i].max_v > target_mid && jedis[i].mid_v > target_min){
            winners.push_back(jedis[i].id);
        }
    }


    cout << winners.size() << "\n";
    for (int i = 0; i < (int)winners.size(); ++i) {
    cout << winners[i] << (i == (int)winners.size() - 1 ? "" : " ");
    }
    cout << "\n";


            
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
