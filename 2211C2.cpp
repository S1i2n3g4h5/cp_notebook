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

    hard version - the array a is arbitary and not any permutaiton given

  */

    ll n,k;cin>>n>>k;
    vll a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    multiset<int> available_a, required_b;

    f(j,0,k){
        bool all_same_a = true;
        bool bwrong = false;
        
        int first_b = -1;

        // print(a[j], " ------------------ ");

        for(int i=j;i<n;i+=k){
            if(a[i] != a[j]) 
                all_same_a = false;
            
            if(b[i] != -1){
                if(first_b != -1 && b[i] != first_b) 
                    bwrong = true;
                
                first_b = b[i];
            }
        }

        // print(all_same_a, "  =  ", bwrong);

        if(!all_same_a){
            // print("all same ai..");
            for(int i=j;i<n;i+=k){
                if(b[i] != -1  and b[i] != a[i]){ 
                    print("NO");

                    return; 
                }
            }
        } 
        else{
            if(bwrong){ 
                print("NO");

                return; 
            }
            
            available_a.insert(a[j]);
            // print(first_b);
            
            if(first_b != -1){
                required_b.insert(first_b);

            }
        }
    }



    for(int val : required_b){
        auto it = available_a.find(val);
       
        if(it == available_a.end()){ 
            print("NO");
            return; 
        }
        
        available_a.erase(it);
    }


    print("YES");


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

    