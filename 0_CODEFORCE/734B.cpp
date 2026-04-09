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



const bool multipleTestCases = false;


bool solve(){
    int two,three,five,six;cin>>two>>three>>five>>six;

    // 256 build up
    ll tot=0;
    if (two>0 and five>0 and six>0){
        int mn_mul = min(two, min(five,six));
        tot += 256*mn_mul;
        
        two-=mn_mul;
        six-=mn_mul;
        five-=mn_mul;
    }
    
    // 32 build up
    if (two>0 and three>0){
        int mn_mul = min(two, three);
        tot += 32*mn_mul;

        two-=mn_mul;
        three-=mn_mul;
    }


    print(tot);

  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);


  cin.tie(0);
  
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    
    while(t--){
  
  
      solve();
  
    }
  
    return 0;
}   