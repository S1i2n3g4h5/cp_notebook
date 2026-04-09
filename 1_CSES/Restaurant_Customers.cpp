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


void solve(){
    int N;cin>>N;
    vector<pair<int,int>>customer;
    f(i,0,N)
    {
        int a,b;cin>>a>>b;
        customer.push_back({a,+1});
        customer.push_back({b,-1});
    }

    /*
        Just focus that when a customer leaves and other arrives
        how will the number of people inside restaurant chnage
    */
    

    sort(customer.begin(), customer.end());
    int cnt=0;
    int mxcnt=0;
    f(i,0,customer.size()){
        cnt += customer[i].second;
        mxcnt = max(mxcnt, cnt);
    }

    print(mxcnt);

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