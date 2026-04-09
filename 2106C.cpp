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



const bool multipleTestCases = 1; 


void solve(){
  /*
    
  */
    ll n,k;cin>>n>>k;
    vector<ll>a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];
    

    ll x=-1;
    f(i,0,n){
        if(b[i] != -1){
            if(x == -1)
                x = a[i] + b[i];
            else{
                if(x != (a[i] + b[i])){
                    print(0);
                    return;
                }
            }
        }
    }
    


    if(x == -1){ // all -1
        print(k - (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end())) + 1);
    }
    else{

        
        f(i,0,n){
            if(x - a[i] > k or a[i] > x){
                print(0);
                return;
            }
        }

        print(1);
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