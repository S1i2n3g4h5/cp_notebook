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
    first step is obviously sorting both out
    so this is kind of greedy strategy
    where we will try binary search to pick the strongest pocket money kids and match them
    to the cheapest biycycle prices.

    just try to find thsi check function ->   personal money spent <= a

    then sum up the purchased prices of bicycles subtract from a,this is our min total personal money needed

    like->  4 5 2
            8 1 1 2
            6 3 7 5 2

    sort out                 1 1 2 8
                             2 3 5 6 7
    personal money (k=2)->   we chose 2,8 mapped with 2,3  so in total -> (0+0)<=a(2)
    personal money (k=3)->   we chose 1,2,8 mapped with 2,3,5  so in total -> (1+1+0)<=a(2)
    personal money (k=4)->   we chose 1,1,2,8 mapped with 2,3,5,6  so in total -> (1+2+3+0) != a(2)

    so k=3 is max valid answer
    now sum up req - {2+3+5} -> 10 - a -> 10 - 2 -> (8)


    -->  also make sure when giving the min prices from pocket money, 
         it can go with max(0, prices - a), as we can have enough money too 
  */
 
    
    ll n,m,a;cin>>n>>m>>a;
    vector<ll>b(n),p(m);
    f(i,0,n)cin>>b[i];
    f(i,0,m)cin>>p[i];


    sort(b.begin(), b.end());
    sort(p.begin(), p.end());


    auto check = [&](ll k){
        ll diff_sm=0;
        for(int i=n-k,j=0;i<n and j<k and (i<n and j<m);i++,j++){
            diff_sm += max(0ll, p[j] - b[i]);
        }
        return diff_sm <= a;
    };

    ll l=0,h=min(n,m);
    while(l<=h){
        ll mid = l + (h-l)/2;
        if(check(mid)){
            l=mid+1;
        }

        else{
            h=mid-1;
        }
    }

    ll prices_sm=accumulate(p.begin(), p.begin() + (l-1), 0ll);

    print(l-1, " ", max(0ll,(prices_sm - a)));

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