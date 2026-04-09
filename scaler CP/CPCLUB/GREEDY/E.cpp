/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   (std::cout << ... << args) << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
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
    maaximizing through sorted prices;

    like utilizing most form usb then ps/2 then the leftovers from both combined
  */
    ll a,b,c,m;cin>>a>>b>>c>>m;
    vll usb,ps2;
    f(i,0,m){
        ll val;
        string type;
        cin>>val>>type;

        if(type=="USB") usb.pb(val);
        else{
            ps2.pb(val);   
        }
    }

    sort(all(ps2));
    sort(all(usb));


    ll cost=0,comps_used=0; 

    int u_idx = 0, p_idx=0;


    while( a > 0 and  u_idx < usb.size()){
        cost += usb[u_idx++];
        comps_used++;
        a--;
    }
    while(p_idx < ps2.size()  and b > 0){
        cost += ps2[p_idx++];
        comps_used++;
        b--;
    }


    vll comb;

    while(u_idx < usb.size()) 
        comb.pb(usb[u_idx++]);
    while(p_idx < ps2.size()) 
        comb.pb(ps2[p_idx++]);
    
    sort(all(comb));

    f(i,0,min(c,(ll)comb.size())){
        cost += comb[i];
        comps_used++;
    }
    
    print(comps_used, " ", cost);

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if(multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
