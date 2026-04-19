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

struct Exchange{
    ll p1,p2;
    char c1,c2;
};

void solve(){
  /*
    minimize the excahnges required to have "win" chars in all people papers

    since the final letters are fixed 3 haracters only we can group them up

    possible groups - win,wni,nwi,niw,inw,iwn

    hence the possible mtches for these groups ares -> 
        - win vs iwn
        - wni vs nwi
        - inw vs niw


    like first priority is those string with 2 dups then the 2nd priority is those having 3 dups

  */

    int n;cin>>n;
 
    
    // categorizing each
    vll wi,iw,wn,nw,in,ni;
    
    f(k,1,n+1){
        string s;cin>>s;

        int w=0,n=0,i=0;
        for(char c:s){
            if(c == 'w')w++;
            else if(c=='n')n++;
            else i++;
        }

        
        if (w == 3) { 
            wi.push_back(k); 
            wn.push_back(k); 
        }
        else if (w == 2) {
            if (i == 0) wi.push_back(k);
            else wn.push_back(k);
        }


        if (i == 3) { 
            iw.push_back(k); 
            in.push_back(k); 
        }
        else if (i == 2) {
            if (w == 0) iw.push_back(k);
            else in.push_back(k);
        }


        if (n == 3) { 
            nw.push_back(k); 
            ni.push_back(k); 
        }
        else if (n == 2) {
            if (w == 0) nw.push_back(k);
            else ni.push_back(k);
        }

    }

    
    // pairng pariotitty one to match 2 dups with each other
    vector<Exchange> ans;
    
    auto match = [&](vll&a, vll&b, char ca,char cb){
        while(!a.empty() and !b.empty()){
            ans.push_back({a.back(), b.back(), ca,cb});
            a.pop_back();
            b.pop_back();
        }
    };

    match(wi,iw, 'w','i');
    match(in,ni, 'i','n');
    match(wn,nw, 'w','n');



    /*
    pairing priority 2 to match all those 3 dups
    like exmaple  -
        - www  needs i,n
        - iii  needs w,n
        - nnn  needs w,i

    1st case WIN triangle
    2nd case WNI traingle
    */

    while(!wi.empty() and !in.empty() and !nw.empty()){
        auto p1 = wi.back(); wi.pop_back();
        auto p2 = in.back(); in.pop_back();
        auto p3 = nw.back(); nw.pop_back();

        ans.pb({p1,p2,'w','i'});
        ans.pb({p2,p3,'w','n'});
    }    

    

    while(!wn.empty() and !ni.empty() and !iw.empty()){
        auto p1 = wn.back(); wn.pop_back();
        auto p2 = ni.back(); ni.pop_back();
        auto p3 = iw.back(); iw.pop_back();

        ans.pb({p1,p2,'w','n'});
        ans.pb({p2,p3,'w','i'});
    }    

    
    print(ans.size());
    for(auto p:ans){
        print(p.p1,p.c1,p.p2,p.c2);
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