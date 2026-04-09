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
    basic conditional greedy strategy to pick max out all to continu eth pattern

    conditiosn - si != si+1  and si!= s+3

  */


  vll counts(3);
  cin>>counts[0]>>counts[1]>>counts[2];


  char colors[] = {'R','G','B'};
  string ans="";

  while(1){
    int best_idx=-1;
    
    f(i,0,3){
        if(counts[i] <= 0)continue;
        if(!ans.empty() and ans.back() == colors[i]) continue;
        if(ans.size() >= 3 and ans[ans.size()-3] == colors[i]) continue;


        if(best_idx == -1){
            best_idx = i;
        }
        else{
            // higher count priority
            if(counts[i] > counts[best_idx]){
                best_idx =i;
            }
            else if(counts[i] == counts[best_idx]){
                // tie breaker
                if(ans.size()>=2 and colors[i] == ans[ans.size()-2]){
                    best_idx = i;
                }
            }
        }
    }

    if(best_idx == -1)break;

    ans += colors[best_idx];
    counts[best_idx]--;
    
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