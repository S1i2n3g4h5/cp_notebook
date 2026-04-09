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
// vector<ll> arr(1e7+1ll, true);

void solve(){    
    string s;cin>>s;

    int cnt=1;
    int mxcnt=1;
    f(i,0,s.size()-1){
        if(s[i]==s[i+1]){   
            cnt++;
        }       
        else{
            cnt=1;
        }
        mxcnt = max(mxcnt,cnt);
    }


    print(mxcnt);

    return;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    
    
    // // sieve primes
    // for(int i=2;i*i<=10000001;i++){
    //     if(arr[i]){
    //         for(int j=i*i;j<=10000001;j+=i){
    //             arr[j]=0;
    //         }
    //     }
    // }
    
    
    while(t--){  
      solve();
    }  
    return 0;
}     
