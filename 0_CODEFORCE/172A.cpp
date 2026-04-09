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
    int n;cin>>n;
    vector<string> arr(n);
    f(i,0,n)cin>>arr[i];


    string long_prefix;
    f(char_idx,0,20){
        long_prefix += arr[0][char_idx];
        bool append =true;

        f(i,0,n){
            if (arr[i][char_idx] != long_prefix[char_idx])
            {
                append=false;
                break;
            }
        }

        if (!append){
            long_prefix = long_prefix.substr(0, long_prefix.size()-1);
            break;
        }

    }

    print(long_prefix.size());
    
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