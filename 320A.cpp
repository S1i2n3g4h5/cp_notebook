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



const bool multipleTestCases = 0;

void solve(){       

    string s;cin>>s;

    f(i,0,s.size()){
        if(s[i]!='1' and s[i]!='4'){
            print("NO");
            return;
        }
    }

    if(s[0] == '4'  or s.find("444")!=string::npos){
        print("NO");
        return;
    }

    print("YES");


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
