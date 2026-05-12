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
    alice maximize, bob minimize

    duplicates are avaialbe hence choosing becoming actual game

    unumbers wiht freq 1, are rare and nede to protect but they become the har limit
    cuz bob will destroy the very 2nd he get the opportuniyty


    so instead of actualliny doing implemetaion simulation we can just 
    assume that alice saving the most imporatant number first, like thsoe having fr 1 or 2 or more
    depending on siwtching turns aucalmtilly, we just need to ensure that the main conditions of fr 0 or 1 are satisfied proeprly
    

  */

    int n;cin>>n;
    vll arr(n);
    map<ll,int>mp;
    f(i,0,n){
        cin>>arr[i];
        mp[arr[i]]++;
    }


    int strike=0;
    ll mex=0;

    f(i,0,n+1){
        int fr = mp[i];

        if(fr==0){
            break;
        }
        else if(fr==1){
            // freq 1 is important but bob wil ltake that sooner or later
            strike++;

            if(strike==2){
                break;
            }
        }

        mex = i+1;
    }

    print(mex);

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