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


  const bool multipleTestCases = 0; 


  void solve(){
    /*
    
    */

    int n;cin>>n;
    

    vector<bool>used(1e5,false);
    vector<pair<ll,ll>> person(1e7);
    vector<ll>ans(1e5);
    f(i,0,2*n+1){

        f(j,1,i){
            ll x;cin>>x;

            person[x].first = i;
            person[x].second = j;
        }
    }

    used[0] = 1;

    for(int i=1e7;i>=0;i--){

        if(!used[person[i].first] and !used[person[i].second]){
            used[person[i].first] = 1;
            used[person[i].second] = 1;

            ans[person[i].first] =person[i].second;
            ans[person[i].second] = person[i].first; 
        }

    }


    f(i,1,2*n+1){
        cout << ans[i] << " ";
    }
    cout <<"\n";


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
