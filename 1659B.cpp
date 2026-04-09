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
    <This  problme statement requires observation and solution to build from observation in problme and specially the conneciton between both outputs - string and its counts of switches>
    
    msb needs to be largest for lexigraphically largest binary string.

    and if k even then no bit change, else change for the ith bit

    now if we ve got k and we subtract some fi from it whihc denotes the count it requires to get max value
    thats already given into your output that we require.

    heres the major observation found->
        k(even) + even -> same bit
        k(even) + odd  -> flip
        k(odd)  + even -> same
        k(odd)  + odd  -> flip

    just use this to start from msb and dry run ,you will get the structured logic for this problem

    so its like if the (bit==1 and k odd) or (bit==0 and k even) -> the bit will end up as 0 so do 1 flip here
  */

    int n,k;cin>>n>>k;
    string s;cin>>s;


    vll counts(n,0ll);
    ll k_rem = k;
        
    f(i,0,n-1){
        if((k > 0) && ( k_rem > 0) && (((s[i] == '1') and ((k%2) ==1)) or ((s[i] =='0') and ((k%2) == 0)))){
            // s[i] = (s[i]=='1'?'0':'1');
            
            counts[i]++;
            k_rem--;
        }
    }
    if(k_rem>0)
        counts[n-1] = k_rem;


    // calc for k-fi
    f(i,0,n){
        // k-fi flips?
        if((k - (counts[i])) % 2 == 1){
            s[i] = (s[i]=='1'?'0':'1');
        }
    }

    cout<<s<<"\n";
    f(i,0,n)
        cout << counts[i] <<(i+1==n?"":" ");
    cout<<"\n";

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