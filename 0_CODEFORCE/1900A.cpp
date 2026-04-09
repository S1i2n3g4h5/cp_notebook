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
    int n; cin>>n;
    vector<char> s(n);
    for(int i = 0; i<n; i++){cin>>s[i];}

    
    int result = 0;

    f(i,0,s.size()){
        int count = 0;
        if(s[i]=='.' ){
            while(s[i]!='#'&& i<n){
                count++;
                i++;
            }
        }
        if(count>=3){
            result = 2;
            break;
        }

        if(count<3) result += count;
    }

    print(result);

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