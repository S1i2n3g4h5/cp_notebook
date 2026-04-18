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
    move right -> many times
    move down -> 1 time only must

    alice -> minimize score  (first turn)
    bob   -> maximize score  (second turn)

    <both witih replacemet strategy like if alice took some its permananetly gone for bob>

    majorly the choice of min sum depends on where exactly the alice changes the rows, cuz from that points
    alice is forced to take all the coins leftover until columne `m`

    ---

    single loop checking for if the alice already taking for this thing, 
    and just directly claculating answer for the bob, cuz once alice changed lane, its done 


    << LOOPHOLE >>
            -> alice isnt minizing the coins on board but instead minimizing the bob's score

  */

    ll m;cin>>m;
    vll r1(m), r2(m);
    f(i,0,m)cin>>r1[i];
    f(i,0,m)cin>>r2[i];
    

    // prefix
    f(i,1,m) r1[i] += r1[i-1];
    f(i,1,m) r2[i] += r2[i-1];


    ll ans=-1;
    f(i,0,m){
        /*  bob potenttial answer
            row1 ->  i+1 to  m-1
            row2 ->  0   to  i-1
        */  
        ll r1_sm = (i == m-1 ? 0 : r1[m-1] - r1[i]);
        ll r2_sm = (i == 0 ? 0 : r2[i-1]);
        
        ll mx = max(r1_sm, r2_sm);


        /*
            essentially we are minimizing this cuz of game theory, 
            as the alice is minimzing the bob score and not the overall whats left on board...

            that is why the bob choses max possible but alice  minimiz it and finalize it cuz alice moves first na..

        */

        if(ans == -1 or mx < ans){
            ans = mx;
        }

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