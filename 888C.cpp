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

    just looping for all unq chars positions

    then finding the max gap for the given chars
    then just min of all these for all chars is the answer

    *for max gap for given char     
        -> start = pos[0] + 1
        -> middle = pos[i+1] - pos[i]   ~repeatitive for all poses
        -> end = n - pos[ pos.size() - 1 ];
  */
  
    string s;cin>>s;
    int n=s.size();

    map<char,vector<int>>freq;
    f(i,0,n){
        freq[s[i]].push_back(i);
    }

    
    int ans=n;

    for(auto [chr, poses]: freq){
        int max_gap = poses[0]+1;

        f(i,0,poses.size() - 1){
            max_gap = max({max_gap, poses[i+1]-poses[i]});

        }

        max_gap = max(max_gap, n - poses.back());

        ans = min(ans, max_gap);

    }
    
    print(ans);


}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
