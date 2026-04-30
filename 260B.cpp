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
    its pure sliding wino and implementaion

  */    

    string s;cin>>s;

    vll days = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    map<string,int> cnt;


    auto valid = [&](string sub){
        if(sub[2] != '-' or sub[5] != '-') return false;

        
        vll validpos = {0,1,3,4,6,7,8,9};
        for(auto x:validpos){
            if(!isdigit(sub[x]))
                return false;
        }


        int d = stoi(sub.substr(0,2));
        int m = stoi(sub.substr(3,2));
        int y = stoi(sub.substr(6,4));

        // valid date?
        if(y < 2013 or y>2015 or m<1 or m>12 or d<1 or d>days[m])
            return false;

        return true;
    };

    f(i,0,s.size()-10+1){
        string sub = s.substr(i,10);
        if(valid(sub)){
            cnt[sub]++;
        }
    }


    string ans;
    int mx=0;
    for(auto x:cnt){
        if(x.second > mx){
            ans = x.first;
            mx = x.second;
        }
    }


    print(ans);

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