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
    since to be div by 90 = 9*10

    for div by 10 there must be atleast 1 zero
    for div by 9 we know that sum of digits should be div by 9

    so here we got only 5...5..5  lets say 5k
    to div by 9 we need to have 9k,18k,27k,36k...
  */

  int n;cin>>n;
  vector<int>arr(n);
  f(i,0,n)cin>>arr[i];
   
  int tot_fives = count(arr.begin(), arr.end(), 5);
  int tot_zeros = count(arr.begin(), arr.end(), 0);
  
    if(tot_zeros == 0){
        print(-1);
        return;
    }
    else{
        if(tot_fives < 9){
            print(0);
        }
        else{
            int kmx = tot_fives - (tot_fives  % 9);
            print(string(kmx, '5'), string(tot_zeros,'0'));
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
