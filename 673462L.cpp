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

void solve(){
  /*
  
    for Yes there cna be k^n possibilites
    this problem is Subsequence Construction Game

    
    */
   
   int n,k,m;cin>>n>>k>>m;
    string s;cin>>s;


    set<char>seen;
    string res="";

    f(i,0,m){
        seen.insert(s[i]);
        if(seen.size() == k){
            res += s[i];

            seen.clear();
        }
    }

    if(res.size() >= n){
        print("YES");
    }
    else{
        print("NO");

        char missing;
        f(i,0,k){
            if(seen.find((char)('a' + i)) == seen.end()){
                missing = (char)('a'+i);
                break;
            }
        }

        while(res.size() <n)
            res += missing;
    
        print(res);
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
