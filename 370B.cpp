/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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

    need to check if given host chosen some numbers and the player only wins with that first

    means no other subset like that exists


  */

    int n;cin>>n;
    vector<vector<int>>cards(n);
    f(i,0,n){
        int x;cin>>x;
        cards[i].resize(x);
        f(j,0,x) cin>>cards[i][j];
    }


    auto is_subset = [&](auto a, auto b){
        for(int x:a){
            bool found=false;
            for(int y:b){
                if(x==y){
                    found=true;
                    break;
                }
            }
            if(!found)
                return false;
        }

        return true;
    };



    f(i,0,n){
        bool winner=true;

        f(j,0,n){
            if (i==j)   
                continue;

            if(is_subset(cards[j], cards[i])){
                winner = 0;
                break;
            }
        }

        if(winner) print("YES");
        else print("NO");
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