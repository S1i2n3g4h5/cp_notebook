/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
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
    in this hard version we can teleport to 0 or n+1 so just need to choose min from both

    but doing this greedily wont work due to constraints so will be using 
    prefix n binary search to get optimal answer

    -> make sure to pick atleast 1 teleport fro left to start the game
  */
 
    int n,c;cin>>n>>c;
    
    struct Teleporter{
        ll left_cost,mn_cost;
    };
    vector<Teleporter> arr(n);
    f(i,0,n){
        ll x;cin>>x;

        arr[i].left_cost = x + i+1;
        arr[i].mn_cost = min(x + i+1, x+(n-i));
    }
    sort(all(arr), [&](auto t1,auto t2){
        return t1.mn_cost < t2.mn_cost;
    });


    // mn_cost prefix
    vll pref(n+1);
    f(i,0,n)
        pref[i+1] = pref[i] + arr[i].mn_cost;


    int ans=0;
    f(i,0,n){

        ll remaining = c - arr[i].left_cost;
        
        
        // here cant use <= cuz then there can a portal having just enough `c` coins to let us pass
        if(remaining < 0){
            continue;
        }
        
        // after stepping through 1 transporter lets chek if others possible
        int cost=1;
        
        
        ll low=0;
        ll high=n-1;
        while(low<=high){
            ll mid = low + (high-low)/2;

            
            ll total_needed = pref[mid + 1];
            int elements_taken = mid + 1;

            if(i <= mid){
                total_needed -= arr[i].mn_cost;
                elements_taken--; 
            }


            if(total_needed <= remaining){
                cost = 1 + elements_taken;
                low = mid + 1;
            } 
            else{
                high = mid - 1;
            }
        }

        ans = max(ans, cost);
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
