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
    formally this problem asks that how many position does each ai selected from l-r range can be moved to empty places which belongs to [1,k];

    like understand it this way, people standing on tiles numbered. then you select some section of people, now
    how many different ways each person has to leave his tile and move left or right just add all those options.
    let arr = [2,4,6,7]    n    k=10
        for ai=2  it has {1,3}       |2|
        for ai=4  it has {3,5}       |2|
        for ai=6  it has {5}         |1|
        for ai=7  it has {8,9,10}    |3|
                          tot ->      8


    left boundary - a[l] - 2   -> considering 1 and al
    right boundary- k-a[r]-1   -> considering last  and ar
    middle covered by ai-1 ai+1-> pf[r-1] - pf[l]
                          
  */
  ll n,q,k;cin>>n>>q>>k;
    vector<ll>arr(n+1);
    f(i,1,n+1)cin>>arr[i];

    vector<ll>pf(n+1,0);
    f(i,2,n){
        ll ways = arr[i+1] - arr[i-1] - 2;
        pf[i] = pf[i-1] + ways;
    }

    // right boundary
    if(n>=2){
        pf[n-1] = pf[n-2] + (n>=3 ? (arr[n] - arr[n-2] - 2) : 0);
    }


    while(q--){
        ll l,r;cin>>l>>r;
        
        if(l==r){
            print(k-1);
            continue;
        }
        

        ll ans=0;

        // left
        ans += arr[l+1] - 2;

        // right
        ans += k - arr[r-1] - 1;

        // middleout
        if(r-l > 1){
            ans += pf[r-1] - pf[l];
        } 

        // print(pf[r], " ", pf[l], " ", ans);
        print(ans);
    }

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