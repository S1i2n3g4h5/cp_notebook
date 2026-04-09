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
vector<int> idxes={9,0,1,2,3,4,5,6,7,8};

void solve(){    
    string s;cin>>s;

    int tot = 4;
    
    if((s[0]-'0') != 1){
        tot+= idxes[s[0]-'0'];
    }
    

    f(i,1,4){

        tot+=abs(idxes[s[i]-'0'] - idxes[s[i-1] -'0']);
    }

    print(tot);
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


