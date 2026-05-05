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

    total ops can be easily calculated cuz we just need to continuously adding the operations
    as there will be +2 ops for each pair off x,y meaning to pick it and put into contian and drop to 0,0,

    and extra +2 ops for botoh x,y until and unless any coordinate is not already 0 cuz we need to return back to it as well


    so for each bomb, the flow is-
        - move to x, if x not 0 then 1 xi R/L
        - move to y, if y not 0 then 1 yi R/L
        - 2
        - return to y
        - return to x
        - 3

  */

    struct Bomb{
        int x,y;
    };

    int n;cin>>n;
    vector<Bomb>arr(n);
    f(i,0,n)cin>>arr[i].x>>arr[i].y;


    ll tot_ops=0;
    f(i,0,n){
        tot_ops += 2;  // type2,3 ops for each pair

        if(arr[i].x != 0) 
            tot_ops+=2;
        if(arr[i].y !=0)
            tot_ops+=2;
    }

    
    print(tot_ops);

    
    sort(all(arr), [&](auto a,auto b){
        return abs(a.x) +abs(a.y)< abs(b.y) +abs(b.x);
    });


    for(auto b:arr){
        // move x
        if(b.x > 0) 
            print(1,b.x,"R");
        else if(b.x < 0)
            print(1,abs(b.x),"L");
            
        // move y
        if(b.y> 0)
            print(1,b.y,"U");
        else if (b.y<0)
            print(1,abs(b.y), "D");
            
        print(2);
        
        // return x
        if(b.x > 0) 
            print(1,b.x,"L");
        else if(b.x < 0)
            print(1,abs(b.x),"R");
            
        // return y
        if(b.y> 0)
            print(1,b.y,"D");
        else if (b.y<0)
            print(1,abs(b.y), "U");


        print(3);

    }


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