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



const bool multipleTestCases = 0; 


void solve(){
  /*
    first lets make the denominators same from given a:b  c:d

    so then ->   ad/bd    and cb/bd

    now just get the remaining area from that ad,cb cuz denominators same

    then just divide by their gcd

  */
 
    int a,b,c,d;cin>>a>>b>>c>>d;

    int numerator1 = a*d;
    int numerator2 = c*b;

    // Forcing numerator1 to be bigger for later difference...
    if(numerator1 < numerator2) swap(numerator1, numerator2); 


    // (max(ad,cb)  -   min(ad,cb) ) / max(ad,cb);
    int new_numerator = (numerator1 - numerator2);
    int new_denominator = numerator1;

    int common = __gcd(new_numerator, new_denominator);
    print(new_numerator/common, "/", new_denominator/common);

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