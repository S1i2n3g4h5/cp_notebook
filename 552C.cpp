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


void generate(int idx, ll sm, vll&v, set<ll>&target){
    if(idx == v.size()){
        target.insert(sm);
        return;
    }

    // right pan
    generate(idx+1, sm + v[idx], v, target);   
    
    // left pan
    generate(idx+1, sm - v[idx], v, target);
    
    // skip
    generate(idx+1, sm, v, target);

}


void solve(){
  /*
    so for all the given weights of 10,w1,w2,w3....
    we got 3 options -
        - put into left pan weigh  (with object m)
        - put into right pan weigh
        - dont use it 


    m + (weigh left) = weigh on right
    m = (right weight) - (left weight)

    hence we to use all w0,w1...w100  we can just assing them coefficients - 0,1,-1
        m = c0w0 + c1w1 + c2w2 ...
    where for the right scle weight using coeficient = 1
          for the left sccle weight using coefficient = 0;
          for not using anythig use coefficient =0;

    

    so the reason we using remainder appraoch


    -----------------------


    another mesmerizing approach is meet-in-the-middle
    which is intutive and better but time contrainted

  */

    ll w,m;cin>>w>>m;


    // ################################################################################3
    //                 meet in the middle technique
    // ################################################################################3
    
    /*  since in this approach the observation remainds same iwth
        this cna work even if the weihts not powers
    */

    if(w == 2 or w == 3){
        print("YES");
        return;
    }


    vll weights;
    ll p=1;
    while(p<=2e9){
        weights.pb(p);

        if(2e9/w < p) break;

        p*=w;

    }



    int mid = weights.size()/2;
    vll leftv,rightv;
    f(i,0,mid)
        leftv.pb(weights[i]);

    f(i,mid,weights.size())
        rightv.pb(weights[i]);



    set<ll>sm1,sm2;
    generate(0,0,leftv,sm1);
    generate(0,0,rightv,sm2);

    
    for(auto x2:sm2){
        if(sm1.count(m - x2)){
            print("YES");
            return;
        }
    }


    print("NO");


    // ################################################################################3
    // ################################################################################3
    
    // while(m>0){
    //     int r = m%w;
    //     if(r == 0){
    //         // mass already multple of w hence easily going 
    //         m/=w;
    //     }
    //     else if(r == 1){
    //         // mass has 1 extra unit so placing 1-kg weihgt on rihgt pan
    //         m = (m-1)/w;
    //     }
    //     else if(r == w-1){
    //         // the mass is 1 unit short of multiple or w
    //         // put the weihgtt on left scale
    //         m = m/w + 1;
    //     }
    //     else{
    //         // all other cases cant possible cuz we only use 1-kg once when required

    //         print("NO");
    //         return;

    //     }
    // }

    // print("YES");

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