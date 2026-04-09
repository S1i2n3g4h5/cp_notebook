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

    int n,m;cin>>n>>m;
    vector<int>correct(n),wrong(m);
    f(i,0,n)cin>>correct[i];
    f(i,0,m)cin>>wrong[i];

    
    int mn_correct = *min_element(correct.begin(), correct.end());
    int mx_correct = *max_element(correct.begin(), correct.end());
    int mn_wrong = *min_element(wrong.begin(), wrong.end());
    
    int v_req = max(2*mn_correct, mx_correct);

    if(v_req >= mn_wrong){
        print(-1);
    }
    else{
        print(v_req);
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
