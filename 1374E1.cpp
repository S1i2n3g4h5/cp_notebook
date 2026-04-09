/*
  Competing against Myself  
  [zoASHro]
*/
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
    since the result will always be determined from following groups
        1. only {11}
        2. {10} + {01}
        3. {11} + {10 + 01};

    also for the -1 condition, we can check  for this size conditions is any is true
    like there needs to have atleast k size for alice or bob else -1
    

    We can create a custom v<v<ll>> arr   with arr[3] denoting the combined {01 + 10}
  */
 
    // _____________________________________________   
    //  Much shorter and effective approach thinking model


    
    ll n,k;cin>>n>>k;
    vector<vector<ll>>arr(3);
    f(i,0,n){
        ll t,a,b;cin>>t>>a>>b;
        if(a==0 and b==0)
            continue;

        arr[a*2+b - 1].push_back(t);
    }

    f(i,0,3){
        sort(arr[i].begin(), arr[i].end());
    }

    
    vector<ll>combined = arr[2];
    f(i,0,min(arr[0].size(), arr[1].size())){
        combined.push_back(arr[0][i] + arr[1][i]);
    }
    
    if(combined.size() < k){
        print(-1);
    }
    else{
        sort(combined.begin(), combined.end());
        print(accumulate(combined.begin(), combined.begin()+k, 0ll));
    }


    // _____________________________________________
    // _____________________________________________

    // ll n,k;cin>>n>>k;
    // vector<vector<ll>>arr(5);
    // f(i,0,n){
    //     ll t,a,b;cin>>t>>a>>b;
    //     if(a==0 and b==0)
    //         continue;

    //     arr[a*2+b - 1].push_back(t);
    // }
    // if( (arr[0].size() + arr[2].size() < k) or (arr[1].size() + arr[2].size() < k)){
    //     print(-1);
    //     return;
    // }
    // f(i,0,3){
    //     sort(arr[i].begin(), arr[i].end());
    // }


    // // creating combined arr[3];
    // f(i,0,min(arr[0].size(), arr[1].size())){
    //     arr[3].push_back(arr[0][i] + arr[1][i]);
    // }
    // sort(arr[3].begin(), arr[3].end());



    // // mx_outs;
    // ll g_01_10 =INFINITY, g_11=INFINITY, g_combined=INFINITY;

    // // group 11 only
    // if(arr[2].size() >= k){
    //     g_11 = accumulate(arr[2].begin(), arr[2].begin() + k, 0ll);
    // }

    // // group 01_10
    // if(arr[3].size() >= k){
    //     g_01_10 = accumulate(arr[3].begin(), arr[3].begin()+k,0ll);
    // }

    // // group 11 + 01+10
    // arr[4].reserve(arr[2].size() + arr[3].size());
    // arr[4].insert(arr[4].end(), arr[2].begin(), arr[2].end());
    // arr[4].insert(arr[4].end(), arr[3].begin(), arr[3].end());
    // sort(arr[4].begin(), arr[4].end());
    // g_combined = accumulate(arr[4].begin(), arr[4].begin()+k, 0ll);


    // print(min({g_01_10, g_11, g_combined}));

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