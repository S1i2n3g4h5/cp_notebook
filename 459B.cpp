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

    ll n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    sort(arr.begin(),arr.end());
    ll min_element = arr[0];
    ll max_element = arr[n-1];

    
    if(min_element != max_element){
        ll cnt_mn =0,cnt_mx=0;
        cnt_mn = upper_bound(arr.begin(),arr.end(),min_element) - lower_bound(arr.begin(), arr.end(), min_element);
        cnt_mx = upper_bound(arr.begin(),arr.end(),max_element) - lower_bound(arr.begin(), arr.end(), max_element);
        // f(i,0,n){
        //     if(arr[i] == min_element){
        //         cnt_mn++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // for(int i=n-1;i>=0;i--){
        //     if(arr[i] == max_element){
        //         cnt_mx++;
        //     }
        //     else{
        //         break;
        //     }    
        // }
        print(max_element-min_element, " ", cnt_mn * cnt_mx);
    }
    else{

        ll nc2 = n*(n-1ll)/2ll;
        print(0, " ", nc2);
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
