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
    
    int n;cin>>n;
    vector<pair<int,int>>arr(n);
    f(i,0,n){
        int x,y;cin>>x>>y;
        arr[i] = {x,y};
    }


    map<int,int>home_freq;
    f(i,0,n){
        home_freq[arr[i].first]++;
    }

    
    f(i,0,n){
        int clash = home_freq[arr[i].second];
        int home_games = n-1 + clash;
        int away_games = (n-1) - clash;

        print(home_games, " ", away_games);
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
