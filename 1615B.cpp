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

const int MAX_BITS=19;
const int MAX_RANGE=200000;
int pre_arr[MAX_BITS][(MAX_RANGE+1)];

const bool multipleTestCases = 1;


void solve(){
  
    int l,r;cin>>l>>r;


    int mxcnt=0;
    f(i,0,MAX_BITS){
        mxcnt = max(mxcnt, (pre_arr[i][r] - pre_arr[i][l-1]));
    }

    print((r-l+1) - mxcnt);

  
  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;   

    f(i,0,MAX_BITS){
        pre_arr[i][0]=0;
        f(num,1,MAX_RANGE+1){
                pre_arr[i][num] = pre_arr[i][num-1] + ((num >> i)&1);
        }
    }


    while(t--){  
      solve();
    }  
    return 0;
}     


