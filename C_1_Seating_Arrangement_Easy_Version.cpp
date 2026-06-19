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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
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

    so its greedy but can be sovled with dp aswell...

    but the main thing is that, we gve priority to I,A,E
    cuz I can occupy the seats given first then A can be attached to any

    now one major thing to notice is that lets say the last seat A sat. and now E
    came s we replace the A with E, cuz A can be converted to E or I anytime, hence its useful to convert
    A to I and make it sit at empty table.

  */

  ll n,x,s;cin>>n>>x>>s;
  string fri;cin>>fri;


  //=====================================================
  //=====================================================
  //=====================================================

  x = min(n,x);
  s = min(n,s);

  vector<vll> seats(x, vll(s,-1));

  f(i,0,n){
    char ty = fri[i];

    // INTROVERT
    if(ty == 'I'){
      for(auto &table:seats){
        if(table[0] == -1){
          table[0] = i;
          break;
        }
      }

    }


    // AMBIVERT
    if(ty == 'A'){
      for(auto& table:seats){
        bool placed = false;

        for(auto& seat:table){
          if(seat == -1){
            seat = i;
            placed=true;
            break;
          }
        }
        if(placed) break;
      }
    }


    // EXTROVERT
    if(ty == 'E'){
      bool placed=false;

      for(auto& table:seats){
        if(table[0] == -1)
          continue;

        if(placed)
          break;

        f(j,1,s){
          if(table[j] == -1){
            table[j] = i;
            placed = true;
            
            break;
          }
        }
      }
    
      if(placed)
        continue;


      ll ambientfriend = -1;
      for(auto& table:seats){
        if(table[0] == -1)
          continue;

        if(placed)
          break;


        f(j,1,s){
          ll currA = table[j];

          if(fri[currA] == 'A'){
            ambientfriend = currA;

            table[j] = i;
            placed = true;
            break;
          }
        }
      }

      if(ambientfriend != -1){
        // swap now...
        bool ambientplace = false;
        for(auto& table:seats){
          for(auto &seat:table){
            if(seat == -1){
              seat = ambientfriend;
              ambientplace = true;
              break;
            }
          }

          if(ambientplace)
            break;
        }

      }

    }

  }


  ll cnt=0;
  for(auto& table:seats){
    for(auto& seat:table){
      if(seat != -1)
        cnt++;
    }
  }

  cout << cnt << "\n";

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