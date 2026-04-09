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



const bool multipleTestCases = 1;


void solve(){       
    ll n;cin>>n;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];



    //trying every element as start of 0?
    
    int ans = 0;
    sort(arr.begin(), arr.end());
    
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    int curr = 0;

    f(i,0,n){
        if(i > 0 && arr[i] == arr[i-1] + 1) 
            curr++;
        else 
            curr = 1;
        
        ans = max(ans, curr);
    }

    print(ans);
    

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
