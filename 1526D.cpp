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
    need to maximize the swaps required by anton
    -> resulting output same chars frequency no change
    -> no. of swap = inversion count to transform a -> b;

    since the distinct chars - 4 only so the total permustaitno is like 24 only which we scan through
    lets dive into this.


    for effective inversion count we would be required to use mtrix that tells effectively which char how much inversion required to be ahead of it

    after building the cost matrix, we can iterate over each permuation to find the best one
    incurring high inversion cost



  */

    string s;cin>>s;
    int n=s.size();

    // a->0   n->1   t->2   o->3
    map<char,int>id = {{'A', 0}, {'N', 1}, {'T', 2}, {'O', 3}};
    ll cost[4][4];

    vector<vll>pf(4,vll(n+1, 0));
    f(i,0,n){
        f(c,0,4){
            pf[c][i+1] = pf[c][i];
        }

        pf[id[s[i]]][i+1]++;
    }


    f(i,0,4){
        f(j,0,4){
            cost[i][j] = 0;
            f(p,0,n){
                if(id[s[p]] == i){
                    cost[i][j] += pf[j][p];
                }
            }
        }
    }


    // permutating
    vll p={0,1,2,3};

    ll mx=-1;
    vll best;

    do{
        ll curr=0;

        f(i,0,4){
            f(j,i+1,4){
                curr += cost[p[i]][p[j]];
            }
        }

        if(curr > mx){
            mx = curr;
            best = p;
        }

    }while(next_permutation(all(p)));

    
    string res="";
    for(int x:best){
        char c = "ANTO"[x];
        int count = pf[x][n];

        res += string(count , c);
    }

    print(res);

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