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



const bool multipleTestCases = false;

bool solve(){
    string s;cin>>s;
    vector<int> prefix(s.size(),0);
    f(i,0,s.size()-1){
        if (i==0)
            prefix[i] = s[i] == s[i+1];
        else
            prefix[i] = prefix[i-1] + (s[i]==s[i+1]);
    }
    
    int n;cin>>n;
    f(i,0,n){
        int l,r;cin>>l>>r;
        l--;
        r-=2;
        if (l==0){
            cout << prefix[r];
        }
        else{
            cout << prefix[r] - prefix[l-1];
        }
        cout << endl;

    }

    return 1;
}

 
int main() {
  ios::sync_with_stdio(0);


  cin.tie(0);
  
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    
    while(t--){
  
  
      solve();
  
    }
  
    return 0;
}   