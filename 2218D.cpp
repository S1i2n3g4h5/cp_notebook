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
    gcd(ai,ai+1) all uniques

    since using even,odds is useless cuz of the factors between them
    evne if using the i,i*2 appraohc is useless cuz this will resut into "1" as duplicated answe

    so need to do somethign which results into unique ones
    and we know that primes are ahving factors 1,p
    and lets say
    primes = p1,p2,p3,p4

    then a1 = p1*p2
         a2 = p2*p3
         a3 = p3*p4

    gcd(a1,a2) = p2
    gcd(a2,a3) = p3 
    and so on..

  */

    ll n;cin>>n;

    // vll arr;

    // f(i,2,n/2+2){
    //     arr.push_back(i);
    //     arr.push_back(i*2);
    //     // cout << i << " " << i*2 << " ";
    // }   

    
    vector<bool>isprime(1000000,true);
    vll primes;
    f(i,2,1000000){
        if(isprime[i]){
            primes.pb(i);

            for(ll j=2*i; j < 1000000; j+=i){
                isprime[j] = false;
            }
        }
    }


    f(i,0,n){
        cout << primes[i]*primes[i+1] << " ";
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