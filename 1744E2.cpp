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
// typedef __int128 ll;
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
    final equaatoin - 
        xy = k(ab)

    here due to large constraints the samme E1 code cant works, getting TLE
    to fix this we can instead go over and iterating over divisors of a,b;
    cuz they are fixed and we are also only finding for the ab/gcd(x,ab)  hence
    iterating over a,b divisors makes more sense than iterating over whole range


    ------

    this problem vaied different from the E1.

    
    here we fatorize a,b separtely to get thte total prime factors of ab;

    then generating all possible divisors D of the product ab iterativerlly

    and finding the largest x<=c  cuz if the smaller can satisfy then larger cna too.


    since x must be a multple of some divisor of the total requirement. we dont know which one will fit the range (a,c], so check em all;

    since we only checking divisors this is fast too.
    

  */

  ll a,b,c,d;cin>>a>>b>>c>>d;


  auto get_prime_factors = [&](ll n, map<ll, int>& counts){
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            counts[i]++;
            n/=i;
        }

    }
    if(n>1)
        counts[n]++;
  };
  

  map<ll,int>prime_counts;
  get_prime_factors(a, prime_counts);
  get_prime_factors(b, prime_counts);


  vll divisors = {1};
  for(auto [p, count] : prime_counts){
    int curr_sz = divisors.size();
    ll p_pow = 1;

    f(i,1,count+1){
        p_pow *= p;

        f(j,0,curr_sz){
            divisors.pb(divisors[j] * p_pow);
        }

    }

  }


  ll tot = a*b;
  for(ll div:divisors){

    ll x = (c/div) * div;


    if(x > a){
        ll need = tot / div;

        ll y = (d / need) * need;

        if(y > b){
            print(x,y);
            return;
        }
    }

  }

    
  print(-1,-1);
    
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