#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    since the single replacement wont work cuz of greedy trap here
    as there are total m pages but we given n pages of that only 
    so it means we've got option to change ai to something which is in range [1,m] but not availbel ing arr[i] okay?

    then ig mean,median,mode.
    most probably median should work;

    okay so median should work but only when checked against all possible neighbours
    like storing each neigbour then looping to find max diff possible then just do - > (initial_diff_sum - mx_diff)
  */
 
    ll m,n;cin>>m>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    // ll sm=0;
    // ll mx_diff=0;
    // f(i,0,n-1){
    //     ll diff = abs(arr[i] - arr[i+1]);
    //     sm += diff;
    //     mx_diff = max(mx_diff, diff);
    // }

    // print(sm - mx_diff);


    ll diff=0ll;
    map<ll,vector<ll>>pages;

    f(i,0,n-1){
        if(arr[i] != arr[i+1]){
            diff += abs(arr[i] - arr[i+1]);

            pages[arr[i]].push_back(arr[i+1]);
            pages[arr[i+1]].push_back(arr[i]);
        }
    }
    
    ll mx_diff = 0;
    for(auto& [curr, neighbours]:pages){
        sort(neighbours.begin(), neighbours.end());

        ll median = neighbours[neighbours.size()/2];

        ll curr_diff=0, median_diff=0;
        for(auto x:neighbours){
            curr_diff += abs(curr - x);
            median_diff += abs(median - x);
        }

        mx_diff = max(mx_diff, abs(curr_diff - median_diff));
    }

    print(diff - mx_diff);

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