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

    ll n,d;cin>>n>>d;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    sort(arr.begin(),arr.end());

    ll tot=0;
    int i=0,j=n-1;
    while(i<=j){
        ll strongest = arr[j];
        ll extra = d/strongest + 1;
        if((j-i) >= extra-1){
            tot++;
            i += extra-1;
            j--;
        }
        else{
            break;
        }
    }
    
    print(tot);
  
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
