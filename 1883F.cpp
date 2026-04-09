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

    since the problem can be olved by locking down both ends pointers for eahc element
    that is, using the first occurance and last occurance data

    the middle duplicates doesnt matter cuz any internal elemnts cna be picked until unless out range and lock is good.

  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    map<int,int>first_occ,last_occ;
    f(i,0,n){
        if(first_occ.find(arr[i]) == first_occ.end()){
            first_occ[arr[i]] = i;
        }
        last_occ[arr[i]] = i;
    }


    vector<int> is_first(n,0),is_last(n,0);

    for(auto p:first_occ){
        is_first[p.second] = 1;
    }
    for(auto p:last_occ){
        is_last[p.second] = 1;
    }


    ll ans=0,curr_firsts=0;
    f(i,0,n){
        if(is_first[i])
            curr_firsts ++;

        if(is_last[i]){
            ans += curr_firsts;
        }
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