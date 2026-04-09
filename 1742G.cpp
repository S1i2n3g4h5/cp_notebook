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
    since the bits total size is atmost 30 only
    then picking up the numbers increasing total OR is befifical
    
  */

  int n;cin>>n;
  vll a(n);
  f(i,0,n)cin>>a[i];


  vector<bool>used(n,false);
  int current_or = 0;
  vector<int> ans;

  f(i,0,min(n,31)){
    int bst_idx=-1;
    int max_or = 0;

    f(j,0,n){
      if(used[j])
        continue;

      
        int res = current_or | a[j];
        if(res > max_or){
          max_or = res;

          bst_idx = j;
        }
    }


    if(bst_idx != -1){
      ans.push_back(a[bst_idx]);

      used[bst_idx] = true;
      current_or |= a[bst_idx];

    }

  }


  for(auto x:ans)
    cout << x << " ";

  f(i,0,n){
    if((!used[i]))
      cout << a[i] << " ";
  }

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