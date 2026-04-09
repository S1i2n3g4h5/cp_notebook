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

    int n,k;cin>>n>>k;
    vector<int>arr(2*n+1);
    f(i,0,2*n+2)cin>>arr[i];


    
    
    for(int i=1;i<=2*n;i+=2){
        // if(arr[a] < arr[b] and arr[b]>arr[c]){
        if (k<=0){
            break;
        }
        if(arr[i] - arr[i-1] >=2 and arr[i]-arr[i+1]>=2){
            arr[i]--;
            k--;
        }
        
    }
    
        
    f(i,0,2*n+1){
        cout << arr[i] << " ";
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
