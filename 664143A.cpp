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
    int n;cin>>n;
    vector<ll>a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];


    ll score = 0;
    
    
    // f(i,0,n){
    //     if(a[i] > b[i]) score += a[i];
    //     else score -= b[i];
    // }

    vector<ll> w(n);
    f(i,0,n){
        
        if(a[i] < b[i]){
            
            score += a[i] - b[i];
        }
        
        w[i] = abs(a[i] - b[i]);
        // print(a[i] - b[i], "  - ", score);
    }

    
    
    // sort(w.begin(), w.end());
    sort(w.rbegin(), w.rend());

    for(int i=0; i<n; i+=2) 
        score += w[i];


    // print(score);
    if(score>0) print("Alice");
    else if(score<0)
        print("Bob");
    else
        print("Tie");

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
