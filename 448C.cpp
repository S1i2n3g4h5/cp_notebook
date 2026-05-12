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

ll func(int n, vll&arr, int l, int r, ll base){
  if(l>r)return 0ll;

  ll hmin = arr[l];
  f(i,l+1,r+1){
    hmin = min(hmin, arr[i]);
  }


  ll vertical_cost = r-l+1;

  ll horizontal_cost = hmin - base;
  f(i,l,r+1){
    if(arr[i] > hmin){
      int start=i,end=i;

      while(end<=r and end<n and arr[end] > hmin){
        end++;
      }


      horizontal_cost += func(n,arr, start,end-1,hmin);

      i=end-1;
    }
  }

  return min(horizontal_cost, vertical_cost);
  
}

void solve(){
  /*
    [[ multiple times painting same 1meter is allowed ]]
    [[  constraints are low  for o(n^2) or maybe somethign recursion ]]

    3 strategies- vertical or horizonotal plan or verticla+horizontal
    
    for vetical, cost = r-l+1
    for horizontal its - first calcauting base comlpete row (by finding the min arri)
        then 2 otions - horizontal agian or vertical

    so more like recursion thing


    ---- 
    actually its got divide-and-conqueror tag, so make sure to remember these types of patterns

    1. paint every plank vertical 
    2. find shortest plank (hmin), painting hmin horizontal stroke across entire range l,r


  */    

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    print(func(n, arr, 0, n-1, 0));


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