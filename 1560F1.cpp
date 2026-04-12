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
    constraints ->  x >= n
    also the minimum, kth beautiful test case

    so we can just iteratively try putting the best char possible

    this is too intuitive and little tricky implementaiton

    
    so the implementation is very similar to fix and recehcking appraoch

    after fixing the failidx we replace all chars with zeroes so as to find the min answer in next iteration automatically
    cuz if we dont do this, the code will find the x>=n that may not be the minimum


  */

    string n;int k;cin>>n>>k;
    int len = n.size();
    
    while(true){
        
        set<char>used;
        int failidx=-1;
        
        for(int i=0;i<len;i++){
            used.insert(n[i]);

            if(used.size() > k){
                failidx = i;
                break;
            }
        }
        // print(fialidx)

        // already correct?
        if(failidx == -1){
            print(n);
            return;
        }

        // print("\t->", n);


        // finding the best possible digit
        for(int i=failidx;i>=0;i--){
            bool found=0;


            // doing n[i]+1 cuz we already knwo that current char is failure
            for(char c=n[i]+1;c<='9';c++){
                set<char>tempused;
                f(j,0,i)
                    tempused.insert(n[j]);

                tempused.insert(c);  // last char changed

                if(tempused.size() <= k){
                    n[i] = c;
                    
                    // replacing next char to be the min
                    f(j,i+1,len)
                        n[j] = '0';
                    
                    found=1;
                    
                    break;
                }

            }

            if(found)break;

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