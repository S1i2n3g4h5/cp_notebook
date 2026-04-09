/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

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
  understand this problem clearly and properly with pen n papers
  its actually easy but just need to understand the problem statement clearly.

  we can only utilize the ai array such that on the ai second we rest.
  the animatorics setting value to +1 is in our hands so to get max damage  we
  will try not to distribute as much and just try keeping the sum such that 
  on lightining 1, another element exists with differenec <=1
  means if a=[10]  and l=10, m=3
  then possibl aniatoics is ->  5 5 0
  which then removing 5 will still remained with max damage as 5.

  so the  maximize -> [l - sum of all enemy we reset]
  which means minimize the enemy with highest danger at each checkpoint given in ai

  and for balancing as much its just that for each ai th time, S mod m buckets having ceil(s/m) and rest having floor(s/m);
  <here s represent the sum of all all buckets + {arr[i]-arr[i-1]}    -> jump

  due to constraints lets just simulate

  Also those adversary will play optimally by knowing that if you got 2 flash left and m=5 then they know you delete 2 highest danger
  so they avoid putting danger into the top 2 which is wasted move, hence to increase overall danger they try for remaining elements 5-2 = 3 animatorics


  */

  ll n,m,l;cin>>n>>m>>l;
  vll a(n);
  f(i,0,n)cin>>a[i];


  multiset<ll>arr;
  f(i,0,m)arr.insert(0);
  
  int idx=0;
  
  f(i,0,l){
    // // +1 updation
    // ll smallest_num = *arr.begin();
    // arr.erase(arr.begin());
    // arr.insert(smallest_num+1);   
    
    // Greedy animatorics logic to avoid the highest being removed so they waste your flashes
    ll rem_idx = n - idx;

    auto it = arr.end();
    for(int k=0;k<=rem_idx and it!= arr.begin();k++){
      it--;
    }

    ll val = *it;
    arr.erase(it);
    arr.insert(val+1);


    if(idx < n and i+1 == a[idx]){
      // highest erase
      arr.erase(prev(arr.end()));
            
      // zero insertion
      arr.insert(0);

      idx++;
    }

  }

  
  print(*arr.rbegin());

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