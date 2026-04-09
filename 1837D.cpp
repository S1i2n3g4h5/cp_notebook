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
  /*
    so exploiting the RBS(regular bracket seq) property of begin neutral => 0

    like for regular RBS, the balance is negative then zero, viveversa for non-RBS;

    and we atmost need 2 colors only cuz we can split string at balance=0 points so we get either RBS or rev-RBS
    and appending RBS+RBS is also RBS so its like just color RBS 1 into first section then 2 for rev RBS;
  */

    int n;cin>>n;
    string s;cin>>s;

    int balance=0;
    f(i,0,n){
        balance += (s[i] == '(' ? 1 :-1);
    }

    if(balance != 0 or n%2 != 0){
        print(-1);
        return;
    }


    
    balance = 0;
    string ans="";
    set<char> used;
    f(i,0,n){
        if(balance == 0){
            if(s[i] == '(')
                ans += "1 ";
            else 
                ans += "2 ";
        }
        else{
            ans += (balance > 0 ? "1 " : "2 ");
        }

        balance += (s[i] == '(' ? 1:-1);
        used.insert(ans[ans.size()-  2]);
    }


    print(used.size());
    if(used.size() == 1){
        f(i,0,n){
            cout << "1 ";
        }
        cout << "\n";
    }
    else{
        print(ans);
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