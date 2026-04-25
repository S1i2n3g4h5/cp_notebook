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
    2 types of moves -
        -> rearrange to q
        -> rearrange to q^(-1)

    and to make exactly k moves, its mossible that we reach s from q
    withint some 5 forward/backwards stes and the remaining (k-t) must be even
    hence then onl we can return to the same good output.

    so when aplying the forward operation its like
        q=2,3,4,1
        this means that 2nd elemnt moves to 1st pos
                        3rd elemnt moves to 2nd pos
                        et.c.

    for backkwardoperation- 
        q=2,3,4,1
        this means that 1 moves to 2nd elem,
        2 moves to 3rd elemn ....

  */

    ll n,k;cin>>n>>k;

    vll q(n+1),s(n+1);
    f(i,1,n+1)cin>>q[i];
    f(i,1,n+1)cin>>s[i];


    vll p(n+1,0);
    f(i,1,n+1)p[i] = i;


    // identity permutation?  but its mandatory to have atleast 1 move
    if(s == p ){
        print("NO");
        return;
    }


    // forward;
    int t_forward = -1;
    f(j,1,k+1){
        vll tmp(n+1,0);
        f(i,1,n+1){
            tmp[i] = p[q[i]];
        }
        p = tmp;

        if(p == s){
            t_forward = j;
            break;
        }


    }


    f(i,1,n+1)p[i] = i;

    int t_backward = -1;
    f(j,1,k+1){
        vll tmp(n+1,0);
        f(i,1,n+1){
            tmp[q[i]] = p[i];
        }
        p = tmp;

        if(p == s){
            t_backward = j;
            break;
        }

    }


    // checking..
    
    bool can=false;

    if(t_forward == k or t_backward == k)
        can=true;
    else{

        if(t_forward == 1 and t_backward==1 and k>1){
            can=false;
        }
        else{
            if(t_forward != -1 and (k-t_forward)%2==0)
                can=true;
            if(t_backward!= -1 and (k - t_backward)%2==0)
                can=true;


        }

    }
    

    if(can)
        print("YES");
    else print("NO");

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