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
    vector<string>arr(n);
    f(i,0,n)cin>>arr[i];


    sort(arr.begin(), arr.end());

    string s;

    f(i,0,n){
        if(s+arr[i] < arr[i]+s){
            s += arr[i];
        }
        else{
            s = arr[i]+s;
        }
    }

    print(s);

  
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


