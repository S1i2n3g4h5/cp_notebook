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

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 1; 


void solve(){
  /*
    all nums containing prime factors other than 2,3 are impossible hence -1

    else well try removing the 3 asfast as possible then only left ops is 2 like 
        num = 2^x * 3^y
        so just need to find way to calcualte by decreasing this 3,2 power (6) or by (2)


    
  */
 
    
  ll n;cin>>n;
    
    ll cnt2=0,cnt3=0;
    while(n%2==0){
        n/=2;
        cnt2++;
    }
    while(n%3==0){
        n/=3;
        cnt3++;
    }


    if(n>1){
        print(-1);
        return;
    }
    

    if(cnt2 > cnt3){  // cuz removing power of 2 is only option when divide by 6   and   adding power of 2 is done by multiply by 2
        print(-1);
    }
    else{
        print((cnt3 - cnt2) + cnt3);
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}