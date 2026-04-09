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

    int k;cin>>k;
    string s;cin>>s;

    int n=s.size();
    int total_1s=count(s.begin(), s.end(), '1');

    if(k>total_1s){
        print(0);
        return;
    }


    int total_subarrays = n*(n+1)/2;

    int k_len_subarrays =(n-k)*(n-k+1)/2;
    

    print(total_1s, " -. ", total_subarrays, ", ", k_len_subarrays);
  
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
