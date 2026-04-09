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
    s smallest by mkaing it ascending order
    t largest by making it descending order

    greedily taking the chars other than a checking wihtout actually implementing those things

    major observation - 'a' char for both as staringg out..
    and ability to rearrange chars anyhow which means even if the t string got some character toher than 'a' wwe can rearrgance is such that its always winning 
    cuz the s string will also be rearrgancd to have 'a' as the first character.


    since the init,start is just regarding the char 'a' into both, after each operatio we just need to keep track of -
        whether the string s has any character other than 'a'  and its size less than t stirng 
    
  */

    ll q;cin>>q;
    
    
    bool has_s_other_char = false, has_t_other_char = false;
    ll s_len=1,t_len=1;
    while(q--){
        ll type,k;string x;
        cin>>type>>k>>x;

        for(char c:x){
            if(type == 1){
                if(c >'a'){
                    has_s_other_char = 1;
                }
                
                s_len += k;
            }
            else{
                if(c>'a'){    
                    has_t_other_char = 1;
                }

                t_len += k;
            }
            
        }
        
        
        if(has_t_other_char){
            print("YES");
        }
        else if(!has_s_other_char and s_len < t_len){
            print("YES");

        }
        else{
            print("NO");
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