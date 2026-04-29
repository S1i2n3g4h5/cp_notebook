/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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


const bool multipleTestCases = 0; 

void solve(){
  /*

  */

    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    ll n;cin>>n;
    string s;cin>>s;


    vll posx 
    
    auto check = [&](ll x) -> bool {
        
    };  


    ll low=0,high=2e9;
    while(low<=high){

        ll mid = low + (high-low)/2;

        if(check(mid)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }

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
/*
    vector<ll> px(n + 1, 0), py(n + 1, 0);
    for (int i = 0; i < n; i++) {
        px[i + 1] = px[i];
        py[i + 1] = py[i];
        if (s[i] == 'U') py[i + 1]++;
        else if (s[i] == 'D') py[i + 1]--;
        else if (s[i] == 'L') px[i + 1]--;
        else if (s[i] == 'R') px[i + 1]++;
    }

    ll low = 0, high = 2e14, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll k = mid / n;
        ll r = mid % n;
        ll windX = k * px[n] + px[r];
        ll windY = k * py[n] + py[r];
        ll currentX = x1 + windX;
        ll currentY = y1 + windY;
        
        if (abs(x2 - currentX) + abs(y2 - currentY) <= mid) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
*/