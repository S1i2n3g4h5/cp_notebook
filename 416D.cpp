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


const bool multipleTestCases = 0; 

void solve(){
  /*
    ap - a,d

    first we find 2 number that are not -1
    then we clacualte d between them
    and if d vald then fill numbres else conitnue next sequence cuz this ap cant be built

    valid ap ->
        1. (a2 - a1)/(i2 - i1) != 0
        2. calucated d must not cause any -1 beofre i1 to become <=0
          cuz  ai = a1 + (i-i1)*d

  */

    int n;cin>>n;
    vll arr(n);
    ll empty=0;
    f(i,0,n){
        cin>>arr[i];
        if(arr[i] == -1) empty++;
    }

    
    int count=0;
    int i=0;
    while(i<n){

        count++;
        int j=i;

        // first fixed element
        while(j<n and arr[j] == -1)j++;
        if(j == n){
            break;
        }

        int first_idx = j;
        j++;

        // second fixed elemnt
        while(j<n and arr[j] == -1) j++;
        if(j==n){
            // only 1 fixed elemnt found
            i=n;
            break;
        }


        int second_idx=j;

        ll diff = arr[second_idx] - arr[first_idx];
        ll dist = second_idx - first_idx;

        if(diff%dist !=0){
            // print("starting new ap..");
            i=j;
            continue;
        }


        ll d = diff/dist;

        if(arr[first_idx] - (first_idx - i)*d <= 0){
            i=j;
            continue;
        }


        // how further till the ap breaks?
        i = j+1;
        while(i<n){
            ll expected = arr[first_idx] + (i - first_idx)*d;
            if(expected<=0)break;
            if(arr[i] != -1 and arr[i] != expected) break;
            i++;
        }

    }

    
    print(count);

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