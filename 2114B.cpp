#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 1;

void solve(){
  /*

    breakdown if conditions
    1. we want to make k good pairs so its basic thing that
       k cannot be greater than total goodPairs possible
    2.
  */
 int n,k;cin>>n>>k;
 string s;cin>>s;
    int one=0,zero=0;
 f(i,0,n){
    if(s[i]=='0') zero++;
    else one++; 
 }

    int good_pairs = zero/2 + one/2;
    int bad_pairs = n/2 - k;

    
    if(k <= good_pairs and 
       (bad_pairs%2 == zero%2) and
       k<=good_pairs and bad_pairs>=0 and 
       bad_pairs <= min(one, zero)){
        print("YES");
    }
    else{
        print("NO");
    }

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
