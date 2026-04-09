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
  
  */
    ll n,m,k;cin>>n>>m>>k;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];
    vector<vector<ll>>operations(m), queries(k);
    f(i,0,m){
        ll l,r,d;cin>>l>>r>>d;
        operations[i] = {l-1,r-1,d};
    }
    f(i,0,k){
        int x,y;cin>>x>>y;
        queries[i]={x-1,y-1};
    }
    

    // --- diff array
    vector<ll>d_freq(m,0);
    f(i,0,k){
        ll l,r;
        l = queries[i][0];
        r = queries[i][1];
        d_freq[l] += 1;
        if(r+1 < m)
            d_freq[r+1] -= 1;
    }
    // vector<ll>cnt(m,0);
    // cnt[0]=d_freq[0];
    f(i,1,m){
        d_freq[i] += d_freq[i-1];
        // cnt[i] += cnt[i-1] + d_freq[i];
    }


    vector<ll>d_array(n,0);
    f(i,0,m){
        ll w = d_freq[i] * operations[i][2];
        // ll w = cnt[i] * operations[i][2];
        d_array[operations[i][0]] += w;

        if(operations[i][1]+1 < n) 
            d_array[operations[i][1]+1] -= w;
    }
    f(i,1,n){
        d_array[i] += d_array[i-1];
    }


    f(i,0,n){
        arr[i] += d_array[i];
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
