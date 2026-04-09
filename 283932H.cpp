#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = 0;


void solve(){       

    string s;cin>>s;
    int nb,ns,nc;cin>>nb>>ns>>nc;
    int pb,ps,pc;cin>>pb>>ps>>pc;
    ll money;cin>>money;
    
    int rb,rs,rc;
    rb = count(s.begin(), s.end(), 'B');
    rs = count(s.begin(), s.end(), 'S');
    rc = count(s.begin(), s.end(), 'C');

    auto check = [&](ll x){
        ll ab,as,ac;
        ab = max(0ll, x*rb -  nb);
        as = max(0ll, x*rs -  ns);
        ac = max(0ll, x*rc -  nc);
        
        return (ab*pb + as*ps + ac*pc) <= money;
    };


    ll l=0,h=5e12;
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(check(mid)){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    print(l-1);

  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
