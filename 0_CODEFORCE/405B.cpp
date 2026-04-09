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


bool solve(){
    
    int n;cin>>n;
    string s;cin>>s;


    int count =0;
    int i=0, j=0;
    bool found_breakeven =false;
    int curr_runnning=0;
    while(j<n){
        // print("\nIndex - ", j);

        if (!found_breakeven){
            // cout << "[FINDING] ";
            if (s[j] == 'L'){
                curr_runnning=0;
            }
            else if (s[j] == '.'){
                i=j;
                curr_runnning++;
            }
            else{
                i=j;
                count+=curr_runnning;
                found_breakeven=1;
                curr_runnning = 0;
                // cout << "    curr sum = " << count << "    ->[FOUND]<-  \n";
            }
        }
        else{
            // cout <<" RL raange... \n";
            if (s[j] == 'R'){
                i=j;
            }
            else if(s[j] == 'L'){
                count += ((j-i+1)%2);
                found_breakeven=0;
                curr_runnning=0;
            }
        }

        j++;
    }

    count += curr_runnning;

    print(count);


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