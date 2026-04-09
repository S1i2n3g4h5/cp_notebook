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


const bool multipleTestCases = 0; 

void solve(){
  /*
    since effective actual rotations will be k%string len   -> mod value;

    constraints are also kind of manageable to run through

    all boils down to moving last k chars to front of whatever left out
  */

    string s;cin>>s;
    int q;cin>>q;

    while(q--){
        ll l,r,k;cin>>l>>r>>k;

        l--;r--;

        int ln = r-l+1;
        k%= ln;

        string temp = s.substr(r-k+1, k) + s.substr(l, ln-k);

        f(i,0,ln){
            s[l+i] = temp[i];
        }

    }


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