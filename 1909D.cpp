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
    so the first idea waas to do somehting by getting the mean of all vals bt thsi is worst method if data got hgh variance

    so another is to using gcd, cuz just a hunch of most questions being math heavy means they only asking for somethign gcd maybe?

    and ig this works by taking the diff and cehcing against that
    
    so its like first need to check for -1 condition which is that we need to have all arri on same pace either all bigger or all lesser   
    cuz if there is some mixed arri then the dividing is not possible from lesser to bigger like if you split bigger num to 2 simpler ones, but you cant go for some anthoer ai
    being lesser than k and spltting it cuz it wont get there and its the constraints.  do dry run

    next is just calculating the diffs and adding all didfs/commongcd -1
    doing -1 cuz to remove the extra arra val we just have now that we splitted

  */


    ll n,k;cin>>n>>k;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    sort(all(arr));


    // all same already?
    if(arr[0] == arr[n-1]){
        print(0);
        return;
    }


    bool all_greater = arr[0] > k and arr[n-1] > k;
    bool all_lesser = arr[0] < k and arr[n-1] < k;

    if(!(all_greater or all_lesser)){
        print(-1);
        return;
    }


    vll diffs(n);
    f(i,0,n){
        diffs[i] = abs(arr[i] - k);
    }

    ll currgcd = diffs[0];
    f(i,1,n){
        currgcd = __gcd(diffs[i], currgcd);
    }


    ll ans=0;
    f(i,0,n){
        ans += (diffs[i] / currgcd - 1);
    }

    print(ans);

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