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
    THIS PROBLEM WAS REALLY GREAT   ---   SHOWED ME A SUBTLE IMPLEMENTATION GAP

                                THANKS :)

  */
 

    int n;cin>>n;
    vector<pair<string,int>>arr(n);
    map<string,ll>final_scores;
    f(i,0,n){
        cin>>arr[i].first >> arr[i].second;
        final_scores[arr[i].first] += arr[i].second;
    }
    

    ll mx = -5e9;
    for(auto p:final_scores){
        mx = max(mx, p.second);
    }

    
    // now running up the sm to find the finalized answer
    map<string,int> current_scores;
    f(i,0,n){
        string name = arr[i].first;
        ll score = arr[i].second;

        current_scores[name] += score;


        // winner conditions
        if(current_scores[name] >= mx and final_scores[name] == mx){
            print(name);
            return;
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