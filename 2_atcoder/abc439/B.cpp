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


    vector<int>cnt(N + 1, 0);

    int lim=sqrt(N);

    f(y,1,lim+1){
        f(x,1,y){
            int s = x*x + y* y;
            
            if (s > N) 
                break;


            cnt[s]++;
        }
    }


    vector<int>good;
    f(i,1,N+1){
        if (cnt[i] == 1) 
            good.push_back(i);
    
    }

    print(good.size());
    if (!good.empty()){
        for(int i=0; i<(int)good.size(); i++) {
            cout << good[i] << (i + 1 == (int)good.size() ? '\n' : ' ');
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1; multipleTestCases and cin >> t;    
    while(t--){  
        solve();
    }  
    return 0;
}
