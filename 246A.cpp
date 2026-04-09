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
const bool multipleTestCases = 0;

void solve(){
  /*
    for duplicates doesnt' work
    just put duplicates descending array first then 1 different element at last
    
    another examples exists are like this -> those creating hill like structure like 
        first 2 elements sorted then its not sorted so the current code will always 
        leave like the first 2 elements swapping and continue with the rest of swapping...
*/

    int n;cin>>n;

    if(n==1 or n==2){
        print(-1);
    }
    else{
        cout << n-1 << " " << n << " ";
        f(i,1,n-1){
            cout << i << " ";
        }
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
