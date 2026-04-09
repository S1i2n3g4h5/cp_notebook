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

    ll n,m;cin>>n>>m;

    /*
    this appoach wrong cuz its not always good to go doubling then subtract
    as we can first subtract then double down for min steps
    */
    // ll k=(ceil(log(m) - log(n)));
    // print(n*(1ll<<k)-m);



    // ______________________
    ll cnt=0;
    while(m>n){
        cnt++;
        if(m%2==0)m=m/2;
        else m++;
    }
    cnt += (n-m);
    print(cnt);

    
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
