/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
    so its like filling in the numbers from each bucket but prioritizing those filling single digit with most zeores

    zero is excepption like everytime its available to be putt into anything

    contraints is limited to 100 so its pure brute force to pick 0,10,100 first
    then we can thkn for those that are mixed 

    -> for mixed numbers we just need to validate if we didnt find any ones or tens digit then taking the mixed nums
    so it can take its place....   writing condition lke this cuz of constraints given, else would have required some other logic 
    to keep track of which places for which mixed number it is.... somethign like that

  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    bool has_zero=false;
    bool has_hundered=false;
    int pure_one=-1, pure_ten=-1, mixed=-1;
    f(i,0,n){
        if(arr[i] == 0) has_zero=1;
        else if( arr[i] == 100) has_hundered = 1;
        else if(arr[i] >= 1 and arr[i] <= 9) pure_one=arr[i]; // 1,2,3...
        else if(arr[i]%10 == 0) pure_ten = arr[i];  // 10,20,30...
        else mixed = arr[i];  
    }


    vector<int>ans;
    if(has_zero) ans.push_back(0);
    if(has_hundered) ans.push_back(100);
    if(pure_one != -1) ans.push_back(pure_one);
    if(pure_ten != -1) ans.push_back(pure_ten);


    // mixed nums need to check the places if needed
    if(pure_one == -1 and pure_ten == -1 and mixed != -1){
        ans.push_back(mixed);
    }


    print(ans.size());
    for(int x:ans) cout << x << " ";
    cout <<"\n";

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