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



const bool multipleTestCases = 1;


void solve(){
    
    ll a,b,kx,ky,qx,qy;
    cin>>a>>b ;    
    cin>>kx>>ky;    
    cin>>qx>>qy;    

    vector<pair<ll,ll>> valid_pos={{a,b},{a,-b},{-a,b},{-a,-b},{b,a},{-b,-a},{-b,a},{b,-a}};
    set<pair<ll,ll>> xpos,ypos;    

    f(i,0,8){
        xpos.insert({kx + valid_pos[i].first, ky + valid_pos[i].second});
        // print(kx + valid_pos[i].first, " ", ky + valid_pos[i].second);
    }
    f(i,0,8){
        ypos.insert({qx + valid_pos[i].first, qy + valid_pos[i].second});
        // print(qx + valid_pos[i].first, " ", qy + valid_pos[i].second);
    }

    int common=0;
    
    for(auto&p:xpos){
        if(ypos.count(p))
            common++;
    }   
    
    print(common);
  
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