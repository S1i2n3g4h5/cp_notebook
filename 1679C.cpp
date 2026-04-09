/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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
    doing brute force simulation implementaiton will result into tle cuz of type 3 query only where need to check if each cell in the submatrix is valid or not

    can use the map or int array to store whether its free or not.
    and for checking can use the ordered_set to check its availability


// For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs

  */


    int n,q;cin>>n>>q;

    vector<int>row(n,0),col(n,0);
    ordered_multiset freerow,freecol;
    f(i,0,n){
        freerow.insert(i);
        freecol.insert(i);
    }

    while(q--){
        int t;cin>>t;


        if(t == 1){
            // insertion
            int x,y;cin>>x>>y;
            x--;y--;

            row[x]++;
            col[y]++;

            if(row[x] == 1){
                freerow.erase(x);
            }
            if(col[y] == 1){
                freecol.erase(y);
            }
        }
        else if(t == 2){
            // deletion
            int x,y;cin>>x>>y;
            x--;y--;

            row[x]--;
            col[y]--;

            if(row[x] == 0){
                freerow.insert(x);
            }
            if(col[y] == 0){
                freecol.insert(y);
            }

        }
        else{
            // check
            int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
            x1--;x2--;y1--;y2--;

            int dx = freerow.order_of_key(x2 + 1) - freerow.order_of_key(x1);
            int dy = freecol.order_of_key(y2 + 1) - freecol.order_of_key(y1);


            if(dx==0 or dy==0) print("Yes");
            else print("No");
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