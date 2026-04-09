#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = 1;



void solve(){    
    
    string s;cin>>s;

    // implement (n+2)/4;
    int n=s.size();


    string ans="";
    int carry = 2;

    for(int i=n-1;i>=0;i--){
        int sm = (s[i]-'0') + carry;
        s[i] = (sm%10) + '0';
        carry = sm/10;
        
        if(!carry)
            break;
    }



    
    if(carry) 
        s.insert(0, 1, carry+'0');

    // print(s);
    
    
    int rem = 0;
    for(auto c:s){
        int val = rem*10 + (c-'0');
        
        rem = val%4;
        if(ans.empty() and val/4==0){
            continue;
        }

        ans += (val/4 + '0');

        // print(c, "  -> ", rem, "  ", ans);
    }

    
    if(ans.size()>0){
        print(ans);
    }
    else print(0);

  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     