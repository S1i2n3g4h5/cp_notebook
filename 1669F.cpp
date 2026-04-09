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
    2 pointer is easy, lets try the suffix+binary search method
  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    vll suffix(n,0);
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1] + arr[i];
    }
    reverse(all(suffix));


    ll alice=0;
    int ans=0;
    f(i,0,n){
        alice += arr[i];

        auto it = lower_bound(all(suffix), alice);
        if(it != suffix.end() and *it == alice){

            int alice_candy = i+1;
            int bob_candy = distance(suffix.begin(), it) + 1;

            if(alice_candy + bob_candy <=n){
                ans = max(ans, alice_candy+bob_candy);
            }

        }

    }

    print(ans);

    // int i=0,j=n-1;
    // int alice=0,bob=0;
    // int ans=0;
    
    // while(i<=j){

    //     if(alice < bob){
    //         alice += arr[i];
    //         i++;
    //     }
    //     else{
    //         bob += arr[j];
    //         j--;
    //     }

    //     if(alice == bob){
    //         ans = max(ans, i+ (n-j-1));
    //     }

    // }
    
    // print(ans);

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
