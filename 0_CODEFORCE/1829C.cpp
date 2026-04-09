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
    // vector<pair<int,string>> a(n);
    int mn_all_one= 1e6+1, mn_lone= 1e6+1, mn_rone= 1e6+1;
    
    f(i,0,n){
        // pair<int,string> p;
        // cin>>p.first >> p.second;
        int t;string s;
        cin>>t>>s;
        // a[i]=p;

        if (s == "11"){
            mn_all_one = min(mn_all_one, t);
        }
        else if (s == "10"){
            mn_lone = min(mn_lone, t);
            
        }
        else if (s == "01"){
            mn_rone = min(mn_rone, t);

        }
    }

    if (mn_all_one == 1e6+1 and (mn_rone==1e6+1 or mn_lone == 1e6+1)){
        print(-1);
        return 1;
    }

    print(min(mn_all_one, mn_rone+mn_lone));


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