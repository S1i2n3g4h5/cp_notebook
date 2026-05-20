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
    onyl values given  - 0,1,2
    2 options - 
        1. paint current blue elment red
        2. using the values thinking as battery we recharge 
           if the arr[i]>0 and arr[i]==R and arr[i+1]==B 
           so decrease arr[i]-- and make arr[i+1]=B

    normal intution semes to use right to left greedy but it fails
    cuz 0 1 0 2 0    here we just need 2 coins
    so doing wiht window like if i need to find 2s and color its djacent first then finding the 1s then zeroes

    cuz 2s cna potentially color its adjacent 2 neighbours saivng 2 coins.


    so we go from left toright, cuz using block of 1 we sve a color 0, and using block 2 we save l

  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];

    vector<bool> colored(n,false);
    ll ans=0;

    f(i,0,n){

        if(arr[i] > 0){
            // # coins requried only 1 then its just whle ops2
            ans++;

            ll start=i;
            ll mx=0;
            while(i<n and arr[i]>0){

                mx = max(mx, arr[i]);
                colored[i] = true;
                i++;
            }
            int end = i-1;

            
            if(mx == 1){
                // eating 1 zero, priority to left
                if(start > 0 and arr[start - 1] == 0 and !colored[start - 1]){
                    colored[start - 1] = true;
                }
                else if(end < n-1 and arr[end+1] == 0 and !colored[end+1]){
                    colored[end+1] = true;
                }
            }
            else if(mx == 2){
                if(start> 0 and arr[start-1] == 0)
                    colored[start-1] = true;
                if(end < n-1 and arr[end+1] == 0)
                    colored[end+1] = true;
                
            }
            i--;
        }

    }


    f(i,0,n){
        if(arr[i] == 0 and !colored[i]){
            ans ++;
            colored[i] = true;
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