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
    on dry run we find that starting from starting point i.e. n=6
        then stirng is  aaaabb  only 1 k
        if left shift b then string is  aaabba,   aaabab   so k=2

        similarly repeat to find that index n-1   given kk=1
        index n-2 gives k=2,3
        index n-3 gives k=4,5,6....

    so calcuating the possible k resulting in group -> first_b_dist
    denoting how far the first b is from the right
    so first b dist is 0 indexed from left i.e.  n-first_b_dist-1;
    and another n-k converting from left to right sided dist
  */

    ll n,k;cin>>n>>k;

    string s(n,'a');

    
    ll first_b_dist = 1;
    while(k > first_b_dist){
        k -= first_b_dist;
        first_b_dist++;
    }


    s[n-1-first_b_dist] = 'b';
    s[n-k] = 'b';

    print(s);

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