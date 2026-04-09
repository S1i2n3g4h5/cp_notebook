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


const bool multipleTestCases = 0; 

void solve(){
  /*
  
  */
    int n,m;cin>>n>>m;  
    
    vector<string>s(n);
    vll tot_freq(26,0);

    f(i,0,n){
        cin>>s[i];
        for(char c:s[i])
            tot_freq[c-'A']++;
    }



    // processing each as lost street
    f(i,0,n){
        vll curr_s_freq(26,0);
        for(char c:s[i]){
            curr_s_freq[c-'A']++;
        }


        ll max_k=m;
        bool possible=1;

        f(c,0,26){
            if(curr_s_freq[c] == 0)
                continue;

            ll others =tot_freq[c] - curr_s_freq[c];
            if(others == 0){
                // missing this and nothing more to build so not possible
                possible=0;
                
                break;

            }
            else{
                // ceiled op
                ll sacrifice = (curr_s_freq[c] + others -1 )/others;   
            
                if(sacrifice > m){
                    possible=0;
                    break;
                }

                max_k = min(max_k, m - sacrifice);
            }

            
        }

        if(!possible)
            cout << -1 <<" ";
        else{
            cout << max_k << " ";
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
