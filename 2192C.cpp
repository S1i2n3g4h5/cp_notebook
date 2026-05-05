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
#define f(i, a, b)          for(ll i = a; i < b; i++)
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
    the firing time ere doesnt matter and only the time taking is reloading

    for easrly soptting need to do maimize damaga as possible

    when h>totalsum of bullets -> the cycles doenst really affect to do which swap, hence we can continue to keep and only do swapping for the remainig swap required,
    when h<totalsum  ->   this is similar case to above with cycles=0 and this is the remaning one only


    there are 2 approaches for thsi-
        1. binary search for optimal T
        2. prefix suffix counting and maths  (seems optimal)

    -----

    but the vairaiont could be taking into account for firing time then it could be more complexprobelm
    where better resource managament needs to be done.

  */

    ll n,h,k;cin>>n>>h>>k;
    vll arr(n);
    f(i,0,n){
        cin>>arr[i];
    }



    // //##############################################################################
    // //       doing   prefix suffix approach     [ o(n) ]
    // //##############################################################################
    
    // vll pf(n);
    // pf[0] = arr[0];
    // f(i,1,n) pf[i] = pf[i-1]+arr[i];
    
    // ll total_sum = pf[n-1];
    
    
    // /* 
    //     for handling the last magazine withouth edge cases we doing h-1  cuz if h=100 and totsum =50  the cycle=2  
    //     but we know that enemy died on last bullet of magazin and didnt required 2nd realod (which is the bug!)
    // */
    // ll magazine_till_last = (h-1) / total_sum;
    // ll time_till_last_magazine = magazine_till_last*n + magazine_till_last*k;
    
    // h -= magazine_till_last * total_sum;
    
    // if(h<=0){
        //     print(time_till_last_magazine);
        //     return;
        // }
        
        
        // vll max_from_right(n,0);
        // max_from_right[n-1] = arr[n-1];
        // for(int i=n-2;i>=0;i--){
            //     max_from_right[i] = max(max_from_right[i+1], arr[i]);
            // }
            
            // vll min_from_left(n);
            // f(i,0,n){
                //     min_from_left[i] = min((i==0 ? arr[0] : min_from_left[i-1]), arr[i]);
                // }
                

                // f(i,0,n){       
    //     ll curr_sum = pf[i]; 
    //     if(i+1<n)
    //         curr_sum = curr_sum - min_from_left[i] + max_from_right[i+1];
    
    //     if(h <= curr_sum or h <= pf[i]){
        //         print(time_till_last_magazine + (i + 1));
        //         return;
        //     }
        
        // }
        
        




    // //##############################################################################
    // //       doing   binary search     [ o(nlogn) ] slightly expensive but stable check()
    // //##############################################################################

    
    vll pf(n), pfmin(n), sfmax(n);
    ll curr_min=2e9,total_sum=0;
    f(i,0,n){
        curr_min = min(curr_min, arr[i]);

        total_sum += arr[i];

        pf[i] = total_sum;
        pfmin[i] = curr_min;
    }

    ll curr_max=-1;
    for(ll i=n-1;i>=0;i--){
        curr_max = max(curr_max, arr[i]);
        sfmax[i] = curr_max;
    }


    auto check = [&](ll mid){
        ll cycles = mid / (n + k);
        ll rem = mid % (n+k);

        ll bullets = min(rem, n);
        ll base_damage = 0;
        if(cycles > 0){
            if(total_sum >= (h + cycles-1)/cycles){
                return true;
            }

            base_damage = cycles * total_sum;
        }

        if(base_damage >= h) return true;


        ll needed = h - base_damage;
        ll rem_damage = (bullets > 0) ? pf[bullets - 1] : 0;


        // attempting swap?
        if(bullets >0 and bullets< n){
            ll best_swap = rem_damage - pfmin[bullets - 1] + sfmax[bullets];
            
            rem_damage = max(rem_damage, best_swap);
        }

        return rem_damage >= needed;
    };


    ll low=1, high=5e18;
    ll ans = high;
    while(low<=high){
        ll mid = low + (high-low)/2;

        if(check(mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
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