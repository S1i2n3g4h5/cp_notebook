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
    int available_bread, available_cheese,available_sauce; 
    cin>>available_bread>>available_sauce >>available_cheese;
    int price_bread, price_sauce,price_cheese;
    cin>>price_bread>>price_sauce>>price_cheese;
    ll money;cin>>money;



    int req_bread = count(s.begin(), s.end(), 'B');
    int req_sauce = count(s.begin(), s.end(), 'S');
    int req_cheese = count(s.begin(), s.end(), 'C');

    auto can_make = [&](const ll x){
        ll req_b = max(0ll,x*req_bread - available_bread);
        ll req_s = max(0ll,x*req_sauce - available_sauce);
        ll req_c = max(0ll,x*req_cheese - available_cheese);
    
        ll cost= (req_b * price_bread) + (req_s * price_sauce) + (req_c * price_cheese);
    
        return cost <= money;
    };


    ll l=0ll, h=1e13;
    ll ans;
    while(l<=h){
        ll mid = l+(h-l)/2ll;
        if(can_make(mid)){
            ans = mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    print(ans);
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


