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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
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

    so the moves ehavily depend on A,b big or samlle..

    if a<=b then,
        each pair exactly 1 unit of X and 1 unit of Y, thereforce min(x,y) *2A
        but if x>y then x-y horixzontal stpes left to make...
        if x-y even then  its just -> (x-y)/2 * (a+b)  <--- last step
        if(x-y) odd, then singe left...   so odd index left, hence add +A

        if(y>x) then y-x vertical steps left...
        if(y-x) even, then cost-> (y-x)/2 * (a+b);
        if(y-x) odd, then cost .. +B;

    if(a>b) then,
        similar as above... .

        if  x>y then x-y leftover horizontal steps.... even pair-> (x-y)/2 * (a+b)
            for odd pair-> +A extra cost..
        if y>x --- y-x lefover vertical steps.... 
            even pairint -> y-x/2(a+b) 
            odd pair -> +b cost added

  */

    ll a,b,x,y;cin>>a>>b>>x>>y;

    x = abs(x);
    y = abs(y);


    if(a>b){
        swap(a,b);
        swap(x,y);
    }

    ll total_cost =0;
    ll common = min(x,y);


    // if(a<=b){
    //     total_cost += common * (2*a);
    // }
    // else{
    //     total_cost += common * (2*b);
    // }
    
    total_cost += common * (2*a);
    
    ll remx = x - common;
    ll remy = y - common;



    /*
        chkf for the moving  stpes to match even stpes... better somtiems..
        rather tahn overgong
        like if A very expensive we just do B cost which is cheap

        like for moving 2 steps-> URUR
        then the cost = b+b+b+b=4b...
        hecen horizontal cost and vertical cost can be compardd.

    */    
    ll pair_cost = min(a+b, 4*a);


    if(remx>0){
        // leftover horizontal step..
        total_cost += (remx/2) * pair_cost;

        if(remx%2 == 1){
            total_cost += a;
            // total_cost += singlecostx;
        }
    }
    else if(remy>0){
        // leftover vertical stpes
        total_cost += (remy/2) * pair_cost;
        if(remy&1){
            // total_cost += b;
            total_cost += min(b,3*a);
            // total_cost += singlecosty;
        }
    }


    cout << total_cost << "\n";

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