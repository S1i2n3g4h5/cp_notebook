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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
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

    so the problem is like, since we are give the array, [1,2,3,4,5]
    the current difference sum-> 1+1+1+1 = 4
    so is there any way to delete some numbers and still get thedifference as 4 only
    which is true, since the another answer would be 1,5 only 
    hwich is length>=2 (satisfying constrain given in condition)
    and we able to ge the max aswell


    and since th max is alway the total differences of the initla array we just need to make sure we get sufficient numbers to retur

    so on close observation we need to remove those numbers which are inot range
    like for array ->  1,3,4,2
    max = 5
    but the answer for subsequcen =1,4,2

    so we need to remove 3, which is observed cuz 3 is in range [1,4] hwihc is its neigbours...

    -> the first and the last element must be included

  */

    ll n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    vll b = {arr[0]};
    f(i,1,n-1){   
        if(abs(arr[i] - arr[i-1]) + abs(arr[i] - arr[i+1]) == abs(arr[i-1] - arr[i+1])){
            // dont take this element its redundant
        }
        else{
            b.push_back(arr[i]);
        }
    }    
    b.push_back(arr[n-1]);


    cout << b.size() <<"\n";
    for(auto x:b){
        cout << x << " ";
    }
    cout <<  "\n";

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