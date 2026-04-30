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
    the array b must be a subset of arry a, if not then its not possibel to have those eletns results equal a==b

    and for replacing the most imp conditions to stay true is that ai<=bi  if not then its impossible

    we just search for both left and right side for the optimal path

    for the raoadblock conditions -
        1. a[j] > b[i] - checks if a new max(arr[i]) found then its not possibel
        2. b[j] < b[i] - lets say A=[10,2,2]   B=[10,5,10]
                          hence if we apply ops [0,2] A=[10,10,10]but actually we wanted
                          to have 5 in middle this is just what sit schecking.
                          we cant carry big value across a spot where its suppose to stay small


  */


    int n;cin>>n;
    vll a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    f(i,0,n){

        if(a[i] == b[i])continue;


        if(a[i] > b[i]){
            print("NO");
            return;
        }


        bool found=0;


        for(int j=i-1;j>=0;j--){
            if(a[j] > b[i] or b[j] < b[i]){
                break;
            }
        
            if(a[j] == b[i]){
                found=1;
                break;
            }
        }


        if(found)continue;

        f(j,i+1,n){
            if(a[j] > b[i] or b[j] < b[i])
                break;

            if(a[j] == b[i]){
                found=1;
                break;
            }
        }


        if(!found){
            print("NO");
            return;
        }

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