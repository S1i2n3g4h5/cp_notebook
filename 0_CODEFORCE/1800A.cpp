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



const bool multipleTestCases = true;


bool solve(){
    
    int n;cin>>n;
    string s;cin>>s;

    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        return tolower(c);
    });


    string target="meow";

    int cnt=0;

    f(i,0,n){
        if (s[i] == target[cnt]){
            cnt++;
        }
        else if (target.find(s[i]) == std::string::npos){
            cnt--;
            cnt =max(0,cnt);
        }
    }

    if(cnt == 4){
        print("YES");
    }
    else
        print("NO");

  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   