  /*
    Competing against Myself  
    [zoASHro]
  */
  #pragma GCC optimize("O2")  
  #include <bits/stdc++.h>
  using namespace std;

  template <typename... Args>
  void print(Args&&... args){
      (std::cout << ... << args) << "\n";
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

    int tx,ty;cin>>tx>>ty;


    // if(tx + ty == 0){ // wrong the x,y could be -1 1 or 1 -1 ?? lol:)
    if(tx==0 and ty==0){
        print(0);
        return;
    }


    int x=0,y=0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    
    int turns = 0;
    
    int steps_to_move = 1;
    
    int segment_len =0;
    int direction=0;

    while(true){

        f(i,0,steps_to_move){
            x+= dx[direction];
            y+= dy[direction];

            if(x==tx and y==ty){
                print(turns);

                return;
            }

        }


        turns++;
        direction = (direction +1)%4;
        segment_len++;

        if(segment_len==2){
            steps_to_move++;
            segment_len =0;
        }
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
