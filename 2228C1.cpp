/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 1; 

void solve(){   
  /*

    low constraints for n=2 only
    d1 < d2

    mathcing greedily the best string digtis positions

    ---

    minimizing targets for the stuff required.
    

  */
    
    string a;ll n;
    cin>>a>>n;    
    int d1,d2;
    cin>>d1>>d2;


    int total_rem = a.size();

    ull target = stoull(a);

    ull ans = ULLONG_MAX;
    
    
    auto rep_ans = [&](string s) {
        if(s.empty()) 
            return;
        
        ull val = stoull(s);
        ull diff = (target>val ? (target - val) : (val - target));
        
        // ans = min(ans, abs(target - val));
        ans = min(ans, diff);
    };



    // min?    
    if(total_rem> 1){
        rep_ans(string(total_rem - 1, '0' + d2));
    }
    // max?
    int min_non_zero = (d1 == 0 ? d2:d1);
    if(min_non_zero != 0){
        rep_ans(to_string(min_non_zero) + string(total_rem, '0' + d1)); 
        
    }


    if (d1 == 0) {
    
        rep_ans("0");
    }


    string done = "";
    
    f(i,0,total_rem){
        int remaining = total_rem - (i+1);
        
        rep_ans(done + to_string(d1) + string(remaining, '0'+d1));
        rep_ans(done + to_string(d2) + string(remaining, '0'+d1));
        rep_ans(done + to_string(d2) + string(remaining, '0'+d2));
        rep_ans(done + to_string(d1) + string(remaining, '0'+d2));


        int curr_digit = (int)(a[i] - '0');
        if(curr_digit == d1 or curr_digit == d2) {
            done += a[i]; 
        } 
        else{
            
            done = "invalid";

            break; 
        }
    }


    if (done != "invalid" and done.size() == total_rem){
        rep_ans(done);
    }
    

    print(ans);

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}