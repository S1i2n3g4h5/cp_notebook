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


const bool multipleTestCases = 1; 


  void solve(){
    int n, x, y;
    if (!(cin >> n >> x >> y)) return;
    vector<int> p(n);
    f(i, 0, n) cin >> p[i];

    // Middle block B and Outer sequence O
    vector<int> B, O;
    f(i, x, y) B.pb(p[i]);
    f(i, 0, x) O.pb(p[i]);
    f(i, y, n) O.pb(p[i]);

    // Find lexicographically smallest rotation of B
    int m = B.size();
    int i = 0, j = 1, k = 0;
    while (i < m && j < m && k < m) {
        int a = B[(i + k) % m], b = B[(j + k) % m];
        if (a == b) k++;
        else {
            if (a > b) i += k + 1;
            else j += k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    int start_B = min(i, j);
    vector<int> B_prime;
    f(l, 0, m) B_prime.pb(B[(start_B + l) % m]);

    if (x == 0 || y == n) {
        // If one portal is at the end, we can rotate the whole array
        vector<int> A = B_prime;
        for (int val : O) A.pb(val);
        
        int nn = A.size();
        int ii = 0, jj = 1, kk = 0;
        while (ii < nn && jj < nn && kk < nn) {
            int a = A[(ii + kk) % nn], b = A[(jj + kk) % nn];
            if (a == b) kk++;
            else {
                if (a > b) ii += kk + 1;
                else jj += kk + 1;
                if (ii == jj) ii++;
                kk = 0;
            }
        }
        int start_A = min(ii, jj);
        f(l, 0, nn) cout << A[(start_A + l) % nn] << (l == nn - 1 ? "" : " ");
        cout << "\n";
    } else {
        // Otherwise, find the best insertion point for B_prime in O
        int first_diff = -1;
        f(l, 1, m) {
            if (B_prime[l] != B_prime[0]) {
                first_diff = l;
                break;
            }
        }
        int comp = 0; // -1 if B_prime is "smaller" than its own first element
        if (first_diff != -1) comp = (B_prime[first_diff] < B_prime[0] ? -1 : 1);

        int insert_pos = O.size();
        f(l, 0, O.size()) {
            if (B_prime[0] < O[l]) { insert_pos = l; break; }
            if (B_prime[0] > O[l]) continue;
            if (comp == -1) { insert_pos = l; break; }
        }

        vector<int> res;
        f(l, 0, insert_pos) res.pb(O[l]);
        f(l, 0, m) res.pb(B_prime[l]);
        f(l, insert_pos, O.size()) res.pb(O[l]);

        f(l, 0, n) cout << res[l] << (l == n - 1 ? "" : " ");
        cout << "\n";
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
