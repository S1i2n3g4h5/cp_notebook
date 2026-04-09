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

ll max_subarray_sum(auto a, int start,int end){
    ll mx = -2e18;
    ll currmx=0;

    f(i,start,end+1){
        currmx += a[i];
        
        mx = max(mx, currmx);

        currmx = max(0ll, currmx);
    }
    return mx;
}

void solve(){
  /*
    
    this is just max subarray sum problem
    condition - adel cant choose the whole array
    so adel has -> [1,n-1]  or [2,n]
  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    ll yasser = accumulate(all(arr),0ll);
    ll adel=max(max_subarray_sum(arr,0,n-2),max_subarray_sum(arr,1,n-1));


    if(yasser > adel){
        print("YES");

    }else{
        print("NO");
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