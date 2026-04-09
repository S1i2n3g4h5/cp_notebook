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


const bool multipleTestCases = 1; 

void solve(){
  /*
    constraints are low for o(n2) checking.
    
    also since the string max len =1000, ts impossible for it to contian all 2chars strings
    as 26^2 = 676 (here some can be duplcicate but its worth checking this space) and
    similarly but the time we get to 3 letter combinations its totally sure that somethign missing up
    


    */

    int n;cin>>n;
    string s;cin>>s;
    
    bool used[26] = {false};
    f(i,0,n)used[s[i]-'a'] = 1;

    
    // finding single char gap?
    f(i,0,26){
        if(!used[i]){
            print((char)(i+'a'));
            return;
        }
    }

    // 2char lens
    f(i,0,26){
        f(j,0,26){
            string tmp = "";
            tmp += (char)('a'+i);
            tmp += (char)('a'+j);

            if(s.find(tmp) == string::npos){
                print(tmp);
                return;
            }
        }

    }


    // 3char lens
    f(i,0,26){
        f(j,0,26){
            f(k,0,26){

                string tmp = "";
                tmp += (char)('a'+i);
                tmp += (char)('a'+j);
                tmp += (char)('a'+k);
                
                if(s.find(tmp) == string::npos){
                    print(tmp);
                    return;
                }
            }
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