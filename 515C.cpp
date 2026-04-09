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

    the question is like we need to find such factorial digits that gives smae factorila results like--

    let f(a) = factorial multiply of each digits
    like 4! = 24
    and 3! * 2! * 2! = 24
    so 4! = 3! * 2! * 2!  ->  output 322   these digits also satisfy the conditions hence its the answer

    we know that for prime number digits (2,3,5,7) cant be divided to broken down
    but for composite numbers (4,6,8,9) we can divide these into steps of other primes factorials

    just find the min possible breakdown of each composite digit which resutls in same f(a) = f(x);
    then its pure implementaion to hardcore the values

    And -> the problem asks for maax possible integer we dont really give shit about the order
    cuz during f(x) we just require the digit so we got the flexibility of rearraging to get max possible number having the max factorial as well ::))

    -----
    
    now for breaking down lets take example -
    to break down 9!
    1. largest prime is 7 so we take 7!
    2. remainder - (9!)/(7!) = 72
    3. repeat step 1 only meaning, breakdown 72, (now since 5!=120 > 72 we cnat fit), try 3!=6 (yes this can fit)  ( here the main conditions is that the number chosen i.e. 3! = 6 so 6 must be divisble as well)
        - can we fit a 3! (6) -> yes  so 72/6 = 12
        - can we fit a 3! (6) -> yes  so 21/6 = 2
        - can we fit 2! (2)   -> yes  so 2/2  = 1

    hence the digits are 7332


    -----

    for breaking down 8!
    1. largest prime is 7
    2. remainder = 8! / 7! = 8
    3. we cant take 3!=6  cuz 8 isnt divisble by 6, so take next small largest that is 2! = 2
        - now since 8 = 2*2*2
        - we take 3 2's

    hence the digits are 7222

  */

    int n;cin>>n;
    string s;cin>>s;


    string primes = "2357";
    string x="";

    f(i,0,n){
        if(primes.find(s[i]) != string::npos){
            x += s[i];
        }
        else{
            if(s[i] == '4') 
                x += "322";
            else if(s[i] == '6')
                x += "53";
            else if(s[i] == '8')
                x += "7222";
            else if(s[i] == '9')
                x += "7332";
        }
    }

    sort(rall(x));

    print(x);


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