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
    since the sums will be same there cannnot be more than 2 distinct vals
    or there can be just 1 distinct vals possible.

    freqcnt condition check for the case of 2 distinct values
        -. n=even n/2 + n/2 = n
        -. n=odd (n-1)/2 + (n+1)/2 = n

        combine both means both their freqcnt diff cannot be > 1
  */

    int n;cin>>n;
    map<int,int>freq;
    f(i,0,n){
        int x;cin>>x;
        freq[x]++;
    }
    
    if(freq.size() >= 3){
        print("No");
    }
    else if(freq.size() == 1){
        print("Yes");
    }
    else{
        int c1=-1,c2=-1;
        for(auto p:freq){
            if(c1==-1){
                c1 = p.second;
            }
            else{
                c2 = p.second;
            }
        }

        if(abs(c2 - c1) > 1){
            print("No");
        }
        else    print("Yes");
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
