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
    vector<pair<int,int>>movies(N);
    f(i,0,N)cin>>movies[i].first >> movies[i].second;


    sort(movies.begin(), movies.end(), [&](const auto p1, const auto p2){
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    });

    int cnt=1;
    int cur_movie =0;
    int i=1;
    while(i<N){
        if(movies[cur_movie].second <= movies[i].first){
            cnt++;

            cur_movie=i;
        }
        
        i++;
    }

    print(cnt);
    
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