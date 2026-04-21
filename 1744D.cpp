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
    first we cna eaisly check the factors of 2 contributing each number arr[i];
    if its >= n then the amount reuqired is already done - 0

    and to fix it we try to greedily pic the even idx first
    like picking those with big index and large count contriution already and doing for thw whole array

    ---
    
    mistake here made is that we don’t need to make the whole array exactly power of 2 but instead just divisible by power of 2

  */
    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    auto powerof2 = [&](ll x){
        return (x&(x-1)) == 0;
    };
    auto count_factor_2 = [&](ll x){
        int cnt=0;
        while(x> 0 and x%2==0){
            x/=2;
            cnt++;
        }
        return cnt;
    };


    ll fct_cnt =0 ;
    f(i,0,n){
        fct_cnt += (count_factor_2(arr[i]));
    }

    
    // fixing
    if(fct_cnt>= n){
        print(0);
        return;
    }

    vll fcts;
    f(i,0,n)fcts.pb(count_factor_2(i+1));
    sort(rall(fcts));


    int ans=0;
    f(i,0,n){
        fct_cnt += fcts[i];
        ans++;

        if(fct_cnt >= n){
            print(ans);
            return;
        }
    }


    print(-1);

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