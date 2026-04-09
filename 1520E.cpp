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
    for empty spaces or with single star the output remains to be 0 only

    for these questions, median is always a way withtou overcompicating things
    */

    int n;cin>>n;
    string s;cin>>s;

    
    vector<int>pos;
    f(i,0,n){
        if(s[i]=='*')
            pos.pb(i);
    }


    // int spaces = count(all(s), '.');
    // if(spaces == 0 or (n-spaces == 1) or spaces == n){
    //     print(0);
    //     return;
    // }

    if(pos.empty()){
        print(0);
        return;
    }


    ll median = pos.size()/2;
    ll ans=0;

    f(i,0,pos.size()){

        ans += abs(pos[i] - pos[median]) - abs(i - median);   

    }


    print(ans);

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
