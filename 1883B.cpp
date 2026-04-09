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

    int n,k;cin>>n>>k;
    string s;cin>>s;


    unordered_map<char, int> freq;
    f(i,0,n){
        freq[s[i]]++; 
    }

    int odd_freq=0,even_freq=0;
    for(auto&p:freq){
        if(p.second%2==1)odd_freq++;
        else even_freq++;
    }
    

    if(odd_freq>k+1){
        print("NO");
    }
    else{
        print("YES");
    }

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


