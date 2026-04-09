#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args) {
    (cout << ... << args) << "\n";
}

#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long

const bool multipleTestCases = 1;


ll simuate_color(ll x,ll y,char first_color){ 

    ll cnt=0;
    ll req_layers=1;
    char curr_color=first_color;

    while(true){
        if (curr_color=='W'){
            if(x<req_layers)break;
            
            x-=req_layers;
        }
        else if (curr_color=='B'){
            if(y<req_layers)break;

            y-=req_layers;
        }

        cnt++;
        req_layers<<=1;

        if(curr_color=='W')curr_color='B';
        else curr_color='W';

    }


    return cnt;
}


void solve(){
    ll a, b;cin>>a>>b;


    ll res = 0;
    
    res = max(res, simuate_color(a,b,'B'));
    res = max(res, simuate_color(a,b,'W'));


    print(res);
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1; multipleTestCases and cin >> t;    
    while(t--){  
        solve();
    }  
    return 0;
}
