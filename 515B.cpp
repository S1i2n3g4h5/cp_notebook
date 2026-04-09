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


const bool multipleTestCases = 0; 

void solve(){
  /*

    since the constraint too small the simulaation can work well as well
    the probelm states like will all pairs eventully meet each other dduring the dinner
    arrangement set   that is   i%n  and i%m

    evne for looping to try each combination, we can go for the 
  */

    int n,m;cin>>n>>m;
    int boy_size,girl_size;
    
    vector<bool>boy_happy(n,false), girl_happy(m,false);
    
    cin>>boy_size;
    f(i,0,boy_size){
        int x;cin>>x;
        boy_happy[x] = true;
    }
    cin>>girl_size;
    f(i,0,girl_size){
        int x;cin>>x;
        girl_happy[x]=true;
    }


    // simulating alll possible cases
    f(i,0,1e6+1){
        int b = i%n;
        int g = i%m;

        if(boy_happy[b] or girl_happy[g]){
            boy_happy[b] = 1;
            girl_happy[g] = 1;
        }
    }


    // check
    f(i,0,m){
        if(!girl_happy[i]){
            print("No");
            return;
        }
    }

    print("Yes");

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