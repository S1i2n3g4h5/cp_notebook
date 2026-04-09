#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 1; 


void solve(){
  /*
    
  */
 

  ll rows,cells,r,c;cin>>rows>>cells>>r>>c;


    auto count_steps = [&](ll d){
        long long steps = 0;
        while (d > 0) {
            d /=2;
            steps++;
        }
        return steps;
    };


    print(count_steps(max(r-1,rows-r)) + count_steps(max(c-1,cells-c)));

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}