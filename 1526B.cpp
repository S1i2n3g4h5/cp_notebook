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
    obse1 - if number of digits for any (111...11) is even then its divsibel by 11

    obse2 - we can build any number thorugh just 11 and 111  
        cuz lets say 1111 -> 11*100 + 11

        and similarly 1111111 -> 11111*100 + 111
                            then here recursively break down (11111*100)
                            and eventually getting 11 or 111 as base

    okay, the final eq build up ->   n = 11a + 111b
        <just found that this is called LINEAR DIOPHANTINE equation>
    Reading cp-algorithms to solve this

    ---

    So this can be solved using 2 ways-
        1. Chicken McNugget theorem -   the largest number that cannot be formed by 2 coprimes p,q is (pq)-p-q
            os the magic number is (11*111)-11-111 = 1099 
            so just brute forcing to find the valid answer available;

        2. Another is Playing with the equation,remainder <linear diphotine> and math way
            yes if (n >= 111*(n%11))  else NO

            here its working like this- 
                since 111 = 11*10 +1
                means every time we use 111 we are adding "1" remainders
                hence e.g. 35 = 33 + 2     ( extra +2 remainder)
                so here to fix this remainder we would be required to use 2(111) which results into 222 but since our number was 35 <222 we cant fix this hence answer NO

            e.g - 244 = 11(22) + 2
                now for fixing remainder 2, its 2(111) = 222
                now 244 > 222 which means answer exists 

  */

    ll n;cin>>n;


    if(n >= 111*(n%11))
        print("YES");
    else{
        print("NO");
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
