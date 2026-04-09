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
     <<<  learnt new concept- pigeonhole principle to be using practically  >>>

    since the editorial tries to query pairs from (3,4)(5,6)(6,7)...(2n-1,2n+1);
        this uses (n-1) queries
    
    now if these loop resutls into 1 then good but if 0
    then it reveals a maths connection -.
        -> (a1,a2) and all (n-1) pairs each contains atmost 1 zero
    
    now the main conditional logic that this holds is like this - 
    <just dont forget that there are n distinct number and n zeroes, cuz whole logic stays on these truths>


    if(1,3) n (1,4) both returned 0 means they dont got any which clearly indicates that
    since there must be some zeores and not much found we can tell that, answer pair exists on 2

    <also we dont require to output both pairs index and just single index, so you knw what i meant?>

  */

    int n;cin>>n;
    
    
    // Query
    f(i,1,n){
        cout << "? "<< 2*i+1 <<" "<<2*i+2 <<endl;
        int ans;cin>>ans;
    

        // checking
        if(ans == 1){
            cout << "! "<< 2*i+1<< endl;
            return;
        }

    }

    // since we used all n queries we still got 1 n+1th query to use
    cout << "? 1 3" << endl;
    int ans;cin>>ans;
    if(ans == 1){
        cout << "! 1" << endl;
    }
    else{
        cout << "? 1 4"<<endl;
        int ans;cin>>ans;
        if(ans){
            cout << "! 1"<<endl;
        }
        else {
            cout << "! 2" << endl;
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