/*
  Competing against Myself  
  [zoASHro]
*/
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

  */

  int n,a,b;cin>>n>>a>>b;
  vector<int>arr1(a),arr2(b);
  f(i,0,a)cin>>arr1[i];
  f(i,0,b)cin>>arr2[i];


    int mxa = *max_element(arr1.begin(), arr1.end());
    int mxb = *max_element(arr2.begin(), arr2.end());

    if(mxa > mxb)
        print("YES");
    else    
        print("NO");

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
