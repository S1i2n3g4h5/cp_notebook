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

ll ans=0, tot=0, target_pos=0;

void backtrack(string&b, int i, int currpos){
    if(i == b.size()){
        tot++;

        // valid ans?
        if(currpos == target_pos){
            ans++;
        }

        return;
    }

    if(b[i] == '+'){
        backtrack(b, i+1, currpos +1);
    }
    else if(b[i] == '-'){
        backtrack(b, i+1, currpos - 1);
    }
    else{
        backtrack(b, i+1, currpos + 1);
        backtrack(b, i+1, currpos - 1);
    }

}


void solve(){
  /*

    if no '?' available then the position is pretty much determinisitic

    but when '?' available,  weneed to go for dp state for "?" cases at any index

    backtracking or even combinatorics can work too, since its basic arithmetic type calculation

    and we need to output the probbility of the correct cases happening out of all cases where '?' provided


    the combinaotrics type solution is really great too, must upsolve again to reason the formula and derivation it leads to...

  */

    string a,b;cin>>a>>b;

    
    
    
    // ________________________________________________________
    //                B A C T R A C K I N G
    // ________________________________________________________

    // for(char c:a){
    //     target_pos += (c=='+'?1:-1);
    // }

    // backtrack(b, 0,0);

    
    // cout << fixed << setprecision(12);
    // print((double)ans/tot);
    
    
    
    
    
    // ________________________________________________________
    //               M A T H S 
    // ________________________________________________________
    
    
    auto ncr = [&](ll n, ll r){
        if(r < 0 or r > n) return 0ll;
        if(r == 0 or r==n) return 1ll;
        
        if(r > n/2)
            r = n-r; 
        

        ll res=1;
        f(i,1,r+1){
            res = res*(n-i+1)/i;
        }
        
        return res;
    };

    
    /*
        let T = target from the string a we need to reach
        then C = current totpositive - current totneg from stirng b

        then gap(diff) = T - C
        which means number of '?' to be filled 

        let k = total question marks
        now lest suppose  p = number of '?' that becomes "+"
                          q = number of '?' that becomes "-"


        then we know that p+q = k
        and similarly  p-q = diff


        add both equations  -
            p+q + p - q = k+ diff
            2p  = k + (T-C)
             p  = (k + T - C) / 2

        now the valid combinations are ncr(k, p);

        this means that the (k+Diff) must be even and odds will result into 0.000 probabability only

    */

    int k = 0;
    int T = 0;
    int C = 0;
    f(i,0,a.size()){
        // a
        if(a[i] == '+') T++;
        else T--;
        
        // b
        if(b[i] == '+') C++;
        else if(b[i] == '-') C--;
        else k++;
    }

    int diff = T - C;


    cout << fixed << setprecision(12);

    if(abs(diff) > k or (k + diff)%2 != 0)
        print(0.0);
    else{

        int totways = pow(2,k);
        int ans = ncr(k, (k + diff) / 2);

        print((double)ans / totways);   
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