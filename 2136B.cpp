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
  /*

  */

    int n,k;cin>>n>>k;
    string s;cin>>s;


    int onecnt=0;
    f(i,0,n){
        if(s[i] == '1')
            onecnt++;
    }

    string consk="";
    f(i,0,k)
        consk.append("1");

    if( s.find(consk) != string::npos){
        print("NO");
        return;
    }


    print("YES");
    int c1=0;
    int c2=count_if(s.begin(), s.end(), [&](char c){
        return c=='1';
    });
    
    f(i,0,n){
        cout << (s[i] == '1' ? ++c1 : ++c2) << " ";
    }
    cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
