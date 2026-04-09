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
    Here the main invariant is finding the constraints and equation clearly.
    using euclidean lemma -> a = pq + r

    a = b*floor(a/b) + a%b;

    now since its given that for pairs to form, floor(a/b) = a%b  = k;
        a = b(k) + k;

    Now we also know that if a%b = k then (k < b) cuz mod value has limited by "b" so the min value of B
    using this equation can be k+1;

    Now take another equation - a = b(k) + k    ---{euclidean lemma}
                                a = k(b + 1)           ----- (1)
                                a/k = b+1                   
                                (a/k) - 1 = b
            From here this equation, we found that the upper found on b is this only


    Also, from the 1st equation  {a=k(b+1)}  and the fact that min value of b=k+1  --
            a = k((k+1) + 1)
            a = k(k+2)
            a = k^2 + 2k;

    Now looking at the constraints ->  1<=a <= x;
            a<=x
            k^2 +2k <= x
            Now looking at the major power player here is k^2
            So k^2 <= x         ->   k <= root(x)   
            cuz if k is greater than root(x) then our major conditions of a<=x wont satisfy
    
  */
 
    ll x,y;cin>>x>>y;


    ll ans=0;
    for(ll k=1;k*k <= x;k++){

        ll lower_bound = k+1;
        ll upper_bound = x/k - 1;

        upper_bound = min(y, upper_bound);   // cuz 1<= b <= y;

        if(upper_bound >= lower_bound){
            ans += upper_bound - lower_bound + 1;
        }
    } 

    
    print(ans);

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