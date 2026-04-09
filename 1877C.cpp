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
    
    main things -> if A[n+1] < n - the value never changes
    if(A[n+1] >= n)  then an becomes some value r < n,  


    Also another key things is  that k cannot be greater than 3
        an+1 is starting value
        an = an+1(mod n)
        an-1 = an(mod n-1)

    Now since an<n, the only way an(mod n-1) produces diffeernt value non-zero is impossible 
    because an x<n mod(n-1)  is either 0 or x;


    Lets understand better- >   
        Given ->   ai = ai+1 (mod i)
        for k=1(only single distinct)
            an+1 must be 0 then only rest all till a0 will lremain same 

        for k=2(only 2 distinct)
            2 ways-
                1st way- 1<= an+1 <=m  and an+1 <n
                2nd way- an+1 is multiple of n

        for k=3(only 3 distinct)
            this happens when an+1 >=n and is not multiple of n

    and since k>3 the answer of ways is 0 cuz, its never possible
    as after k=3 we foud that the last ai=ai+1(mod i) will get 0 from where it wont have any new value change to be distinct again
  */

    ll n,m,k;cin>>n>>m>>k;


    if(k>3){
        print(0);
    }
    else if(k==1){
        print(1);
    }
    else if(k==2){
        // all an+1 such that [1,m] and <n
        ll not_div = min(m,n-1);

        // all an+1 such that [1,m] and multiples of n
        ll div = m/n;

        print(not_div + div);
    }
    else{
        // subtracting from the cases from k=1,2
        ll k_1 = 1;
        ll k_2 = min(m,n-1) + m/n;

        ll tot_ways = m+1;
        print(tot_ways - k_1 - k_2);
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