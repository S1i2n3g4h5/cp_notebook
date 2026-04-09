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
  #define all(x) (x).begin(),(x).end()
  #define rall(x) (x).rbegin(),(x).rend()
  #define pb push_back
  #define f(i, a, b)          for(int i = a; i < b; i++)
  #define debug(x) cout<<#x<<" = "<<x<<ln
  typedef long long ll;
  typedef pair<ll,ll> pll;
  typedef vector<ll> vll;
  


  // ______________________________________________________
  long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
    long long result = 1;
    while(power > 0){
      if(power & 1){result = (result*base) % MOD;}
      base = (base*base) % MOD;
      power = power>>1ll;
    } 
    return result;
  }


  const bool multipleTestCases = 1; 


  void solve(){
    /*
    
    */

    int n;cin>>n;

    if(n==1){
        print(1);
        return;
    }
    else if(n==2){
        print(-1);
        return;
    }


    int a[n][n];
    int diff=1;
    f(i,0,n){
        f(j,0,n){
            a[i][j] = diff;
            if(diff+2<=n*n)
                diff+=2;
            else{
                diff=2;
            }
        }
    }
    f(i,0,n){
        f(j,0,n){
            cout << a[i][j] << " ";
        }
        cout <<"\n";
    }


  }


  int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      
      int t = 1;
      if (multipleTestCases) cin >> t;
      while(t--){
          solve();
      }
      return 0;
  }
