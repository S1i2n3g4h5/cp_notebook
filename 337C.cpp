/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


 
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



const bool multipleTestCases = 0; 


void solve(){
  /*
Main observation - O(1);
    So in this problem we've got to minimize the score that was possible
    like m=tot correct answer,   gap = n-m  (tot wrong answers);
    so before each k blocks of (k-1)'s element we will try to put these wrogn answer so as the asnwer was just about to double, we reset it
    hence using this strategy we can easily get the minimum score possible. 

    
    now then we can easily find the total block available by fixing correct answers on k-1 blocks
    then add the remainign score that may have left after some degree of doubling (cuz we may get run out of wrong answers to put)
    

*Also, binary search possible but kinda tricky ig, will see its code later.
  */
    
    ll MOD = 1e9+9;
    ll n,correct_ans,k;cin>> n>> correct_ans>>k;

    ll wrong_ans = n - correct_ans;
    
    
    ll fixed_block_forced_double = max(0ll, correct_ans - (wrong_ans * (k-1)));
    ll d = fixed_block_forced_double / k;
    ll static_answer_corrrct = (((fast_power(2, d+1, MOD) - 2 + MOD) % MOD) * (k % MOD)) % MOD;

    ll ans = static_answer_corrrct + (correct_ans - d*k);
    ans %= MOD;

    print(ans);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}