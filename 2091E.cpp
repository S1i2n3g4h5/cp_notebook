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


const int maxn = 10000001;
int prime_cnt[maxn];
ll pf_sm[maxn];
bool isprime[maxn];

void precompute(){
    fill(isprime + 2, isprime + maxn, true);

    f(p,2,maxn){
        if(isprime[p]){

            for(int m=p;m<maxn;m+=p){
                isprime[m] = (m == p);
                prime_cnt[m]++;
            }

        }
    }

    f(i,1,maxn){
        pf_sm[i] = pf_sm[i-1] + prime_cnt[i];
    }

}

void solve(){
  /*

    instead of checking from or with random numbers
    we start from primes only, making them our pivot elem


    g = gcd(a,b)  then a=gx    ,  b=gy

    lcm(a,b) = a*b/gcd(a,b)
             = gx*gy / g
             = gxy

    now f(a,b) = g*x*y/g  =>  x*y


    and since we know that x=1   and y=prime  then only this f(a,b) satisfy

  */

    ll n;cin>>n;


    print(pf_sm[n]);

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  

    precompute();

  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}