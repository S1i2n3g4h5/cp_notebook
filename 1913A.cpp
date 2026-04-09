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

    int a=(s[0]-'0'),b=0;

    f(i,1,s.size()){
        if(s[i] == '0'){
            a = a*10 + (s[i]-'0');
        }
        else{
            b =stoi(s.substr(i));
            break;
        }
    }

    
    if(a>=b ){
        print(-1);
    }
    else{
        print(a, " ", b);
    }

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
