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

    string a,b;cin>>a>>b;

    if(a==b){
        print(0);
        return;
    }


    string mn_size, mx_size;
    if(a.size()<=b.size()){
        mn_size = a;
        mx_size = b;
    }
    else{
        mn_size = b;
        mx_size = a;
    }


    // checking . . 
    int mn_start=0, mx_len=0, mx_start=0;
    f(i,0,mn_size.size()){
        f(j,1,mn_size.size()+1-i){
            // print(mn_size.substr(i,j));
            auto mx_string_pos = mx_size.find(mn_size.substr(i,j));
            if(mx_string_pos != string::npos){
                if(j > mx_len){
                    mn_start = i;
                    mx_len = j;
                    mx_start = mx_string_pos;
                }
            }
        }
    }
    
    // print(mn_size.substr(mn_start, mx_len));
    
    // int string_a_dels = (mn_start) + (mn_size.size() - (mn_start +mx_len));
    // int string_b_dels = (mx_start) + (mx_size.size() - (mx_start +mx_len));
    // print(string_a_dels + string_b_dels);

    print(mn_size.size() + mx_size.size() - 2*(mx_len));

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
