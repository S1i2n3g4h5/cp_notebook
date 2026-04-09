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


void printBinary(int n) {
    for (int i=9; i>=0;--i) {
        int mask = (1 << i);
        if ((n & mask) != 0) {
            cout << '1';
        } 
        else {
            cout << '0';
        }
    }
    
    cout << endl;
}
int msb(ll a){
    int mx = 0;
    f(i,0,32){
        if ( ((a>>i)&1) == 1)
            mx = i;
    }
    return mx;
}
void diffBits(ll a,ll b , int msb){
    
    vector<int> diffs;
    f(i,0,msb+1){
        int ath_bit = (a>>i)&1;
        int bth_bit = (b>>i)&1;
        if (ath_bit != bth_bit){
            diffs.push_back(1<<i);
        }
        // diff += ath_bit != bth_bit;
    }
    print(diffs.size());
    f(i,0,diffs.size())cout << diffs[i] << " ";
    cout << endl;
}

bool solve(){

    ll a,b;cin>>a>>b;

    int msba = msb(a);
    int msbb = msb(b);

    if (msbb > msba){
        print(-1);
        return 1;
    }
    else if (a==b){

        print(0);
        return 1;
    }


    diffBits(a,b, msba);

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