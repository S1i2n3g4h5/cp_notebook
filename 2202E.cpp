/*
  Cmd_mxpeting against Myself  
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
#define debug(x) cout<<#x<<" = "<<x<<ln
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


const int MAXA = 1000005;
int mn[MAXA],mx[MAXA],md_mx[MAXA];

void pre(){
    f(i,2,MAXA){
        if(!mn[i]){
            for(int j=i;j<MAXA; j+=i){
                if(!mn[j]) 
                    mn[j]=i;
                
                mx[j] = i;
            }
        }
        
        md_mx[i] = md_mx[i / mn[i]] + 1;
    
    }
}


void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    print(n,x,y);
    
    // Step 1: Divide into regions A, B, and C
    vector<int> A, B, C;
    for (int i = 0; i < x; ++i) A.push_back(p[i]);
    for (int i = x; i < y; ++i) B.push_back(p[i]);
    for (int i = y; i < n; ++i) C.push_back(p[i]);
    
    // Step 2: Combine A and C into sequence S
    vector<int> S;
    for (int val : A) S.push_back(val);
    for (int val : C) S.push_back(val);
    
    // Step 3: Find the minimum element in B to form B_opt
    int min_b_idx = 0;
    for (int i = 1; i < B.size(); ++i) {
        if (B[i] < B[min_b_idx]) {
            min_b_idx = i;
        }
    }
    
    // Create the optimally shifted version of B
    vector<int> B_opt;
    for (int i = 0; i < B.size(); ++i) {
        B_opt.push_back(B[(min_b_idx + i) % B.size()]);
    }
    

    int insert_k = S.size(); // Default to inserting at the end
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] > B_opt[0]) {
            insert_k = i;
            break;
        }
    }
    
    // Step 5: Construct the final array
    vector<int> ans;
    for (int i = 0; i < insert_k; ++i) ans.push_back(S[i]);
    for (int val : B_opt) ans.push_back(val);
    for (int i = insert_k; i < S.size(); ++i) ans.push_back(S[i]);
    
    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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
