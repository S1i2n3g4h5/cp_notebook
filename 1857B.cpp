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

    string s;cin>>s;

    int n = s.size();

    int first_five=-1;
    f(i,0,n){
        if (s[i] >= '5') {
            first_five = i;
            break;
        }
    }
    if(first_five == -1) {
        print(s);
        return;
    }

    
    int round_at = first_five;
    for(int i=first_five-1;i>=0;i--){
        if (s[i] == '4')
            round_at = i;
        
        else 
            break;
    }

    
    if(round_at == 0){
        cout<< "1";
        f(i,0,n)    
            cout << "0";
        cout<< "\n";
    }
    else{
    
        s[round_at - 1]++;
    
        f(i,round_at,n){
            s[i]='0';
        }
        
        print(s);
    }


}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
