#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 1;

void solve(){       

    ll n,k;cin>>n>>k;
    string s;cin>>s;



    // if(k==1){
    //     ll idx = s.find('B');
    //     if(idx !=string::npos)
    //         print(0);
    //     else
    //         print(1);
    //     return;
    // }

    // // first black index
    // ll black_index=-1;
    // f(i,0,n){
    //     if(s[i] == 'B'){
    //         black_index=i;
    //         break;
    //     }
    // }
    
    // if(black_index == -1){
    //     print(k);
    //     return;
    // }


    vector<ll>white_prefix(n);
    white_prefix[0] = s[0] == 'W';
    f(i,1,n){
        white_prefix[i] = white_prefix[i-1] + (s[i] == 'W');
    }


    ll cost = LONG_LONG_MAX;
    ll i=0,j=k-1;
    while(j<n){
        ll curr_whites;
        if(i==0){
            curr_whites = white_prefix[j];
        }
        else{
            curr_whites = white_prefix[j] - white_prefix[i-1];
        }

        cost = min(curr_whites, cost);

        i++;j++;
    }


    print(cost);
    
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
