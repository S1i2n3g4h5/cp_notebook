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
    /**/
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    
    set<char> s_chars, t_chars;
    for(char c : t) t_chars.insert(c);
    for(char c : s) s_chars.insert(c);
    
    
    int q;cin>>q;
    f(i,0,q){
        string w;cin>>w;
        bool is_takahashi = true;
        bool is_aoki = true;

        for(char c : w){
            if(s_chars.find(c) == s_chars.end()){
                is_takahashi = false;
            }
            if(t_chars.find(c) == t_chars.end()){
                is_aoki = false;
            }
        }

        if(is_takahashi && !is_aoki){
            print("Takahashi");
        }
        else if(!is_takahashi && is_aoki){
            print("Aoki");
        }
        else{
            print("Unknown");
        }
    
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
