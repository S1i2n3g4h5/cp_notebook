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


vll arr;
vector<pair<ll, pair<ll, ll>>> moves;


void go(ll i, ll A, ll B, ll C) {
    if(i == 0)
        return;
    
    if(arr[i] == 0) {
        go(i - 1, A, C, B);
        // print("1 -> ", i,A,B,C);
        
        moves.push_back({i, {A, B}});
        
        go(i - 1, C, B, A);
        // print("1/2 -> ", i,A,B,C);
    }
    else{
        int k = i - 1 - arr[i];
        go(k, A, C, B);
        // print("2 -> ", i,A,B,C);
        
        moves.push_back({i, {A, B}});
        
        go(k, C, A, B);
        // print("2/1 -> ", i,A,B,C);
        go(i - 1, A, B, C);
        // print("2/2 -> ", i,A,B,C);
    }
}

void solve() {
    /*

    */

    int n;cin>>n;
    
    arr.resize(n+1);
    moves.clear();
    

    bool possible = true;
    f(i,1,n+1){
        cin>>arr[i];

        if(arr[i] > (i-1)){
            possible = false;
        }
    }


    if (!possible) {
        print("NO");
        return;
    }
    
    
    go(n,1,3,2);
    

    print("YES");
    print(moves.size());
    for(auto& move:moves)
        print(move.first, move.second.first, move.second.second);


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