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
    since the string t will be repating in answer as t+t+t....

    asnd we know that t repeating m times will be of finalze size n only
    so the init t string size will be divisible by n;
    henc elooping for divisors of n for first possible t;


    finding the possible t, using bitmasking kind of technique

    ---
    so as example - 
        3 2
        abc
        baa

    so we found that if d=1  then the indexs for d,2d,3d must be equal hence
    'a' char is okay with d,2d and its our answer


    so another example like 
        4 2
        acbd
        bdac

    so here d=2, we get `a` (char 0 strip 1) with (char 2 strip 2)
    similarly we char `c` (char 1 strip 1) wiith (char 3 strip 2)
    
    the patter  follows  d,2d,3d ....

    ----
    The indices that are "locked" together are always i, i+d, i+2d, because
    They all represent the same position in the repeating block t.
    The problem says the character at index j must come from Column d

  */

    int n,k;cin>>n>>k;
    vector<string>arr(k);
    f(i,0,k)cin>>arr[i];


    vll divisors;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            divisors.pb(i);
            if(i*i != n)
                divisors.pb(n/i);
        }
    }
    sort(all(divisors));


    // 2d bool array to check if char exists or not (quick)
    vector<vector<bool>>exists(n, vector<bool>(26,false));
    f(i,0,k){
        f(j,0,n){
            exists[j][arr[i][j] - 'a'] = true;
        }
    }


    for(int d:divisors){

        string t = "";
        bool found=true;

        f(i,0,d){
            char common_char=' ';

            f(c,0,26){
                bool char_exists_all_col = true;

                // i, i+d, i+2d, i+3d ...
                for(int col=i;col<n;col+=d){
                    if(!exists[col][c]){
                        char_exists_all_col = false;
                        break;
                    }
                }


                if(char_exists_all_col){
                    common_char = (char)('a' + c);
                    break;
                }

            }


            // checking common char
            if(common_char == ' '){
                found=0;
                break;
            }
            else{
                t += common_char;
            }


        }


        if(found){
            f(j,0,n/d){
                cout << t;
            }
            cout << "\n";

            return;

        }

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