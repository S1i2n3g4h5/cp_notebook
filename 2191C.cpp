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
    int n; cin >> n;
    string s; cin >> s;


    if(is_sorted(s.begin(), s.end())) {
        print("Bob");
        return;
    }


    int zeros=0;
    for(char&c:s)if(c == '0') zeros++;

    
    
    vector<int> moves;
    f(i,0,zeros){
        if(s[i] == '1'){

            moves.push_back(i+1);
        }
    }


    f(i,zeros,n){
        if(s[i]=='0'){
            moves.push_back(i+1);
        }
    }
    

    print("Alice");
    print(moves.size());
    f(i,0,moves.size()){
        cout <<moves[i]<<" ";
    }
    cout << "\n";
    
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
