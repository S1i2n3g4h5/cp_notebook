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

  */

    ll n,k,p,m;cin>>n>>k>>p>>m;

    deque<pair<ll,ll>> deck;
    for(int i = 0; i < n; i++){
        int cost;
        cin >> cost;
        deck.push_back({cost, i + 1});
    }


    
    int ans = 0;

    while(true){
        int win_pos = -1;
        f(i,0,deck.size()){
            if(deck[i].second == p){
                win_pos = i; 
                break;
            }
        }

        
        int target_idx = -1;

        if(win_pos < k){
            target_idx = win_pos;
        } 
        else{
            // cheapest play

            target_idx = 0;
            f(i,1,k){
                if(deck[i].first < deck[target_idx].first){
                    target_idx = i;
                }
            }
        }



        if(m >= deck[target_idx].first){
            m -= deck[target_idx].first;


            if(deck[target_idx].second == p){
                ans++;
            }

            pair<ll,ll> played = deck[target_idx];
            deck.erase(deck.begin() + target_idx);
            deck.push_back(played);
        } 
        else{
            // print("Not enough energy left.");
            // print(ans);
            break;
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