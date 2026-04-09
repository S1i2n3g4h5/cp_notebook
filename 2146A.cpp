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
    int n;cin>>n;
    map<int,int>freq;
    int mx_freq=1;
    f(i,0,n){
        int x;cin>>x;
        freq[x]++;
        mx_freq = max(mx_freq,freq[x]);
    }

    int mx_cnt=0;
    int distinct_count=freq.size();
    
    vector<int> f;
    for(auto p:freq){
        f.push_back(p.second);
    }
    sort(f.begin(), f.end());

    for(int b:f){
        int tot_elems = b * distinct_count;
        mx_cnt = max(mx_cnt, tot_elems);
        distinct_count--;
    }

    print(mx_cnt);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
