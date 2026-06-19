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

    So this problem boils down to just do atmost 1 swaps and make the items
    come together.
    
    fellow example can be-  aaabbccbd
    here we just need to swap b with the leftmost c then the string 
    consecutive items will come together


    -> if thinng of sorting and counting the inversion then this wont work, cuz wiht sorting the possitions
       that are already good cna be shifted moved side whcih results into WA

    
  ---------___________----------___________-----------____________

  so now to solve this problem, we just need to fisrt find the first,last position of each elemtn where it appearsts
  and if some other numbres appears in someone else territory then its wrong, and need to fix this intruder.

  and since we allowed atmost 1 swap only, between a[l],a[r];
  we need to fix those violation elemnts in the ranges... and runa final verifcation check
  o each unique number fors exactly single contiguous block.
  

  */


  ll n;cin>>n;
  vll arr(n);
  f(i,0,n)cin>>arr[i];


  auto is_correct = [](vll a, ll n){
    map<ll,ll>lastseen;
    f(i,0,n){
      lastseen[a[i]] = i;
    }

    map<ll,ll>firstseen;
    for(int i=n-1;i>=0;i--){
      firstseen[a[i]] = i;
    }

    for(auto [val, firstidx] : firstseen){
      ll lastidx = lastseen[val];
      
      // finding intruder in the range
      f(k,firstidx, lastidx+1){
        if(a[k] != val){
          return false;
        }
      }
    }
    return true;
  };



  if(is_correct(arr, n)){
    cout << "YES\n";
    return;
  }


  map<ll,ll>lastseen,firstseen;
  f(i,0,n){
    lastseen[arr[i]] = i;
  }
  for(int i=n-1;i>=0;i--){
    firstseen[arr[i]] = i;
  }


  ll L=-1,R=-1;

  // finding first elemnt which is separated from group's end
  f(i,0,n){
    if(lastseen[arr[i]] > i and arr[i] != arr[i+1]){
      L = i+1;
      break;
    }
  }

  // finding last element that i spearted form its group's first
  for(int i=n-1;i>0;i--){
    if(firstseen[arr[i]] < i and arr[i] != arr[i-1]){
      R = i-1;
      break;
    }
  }


  if(L != -1 and R != -1 and L < R){
    swap(arr[L], arr[R]);

    if(is_correct(arr, n)){
      cout << "YES\n";
      return;
    }


    swap(arr[L], arr[R]);
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
