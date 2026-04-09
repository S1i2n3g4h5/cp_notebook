#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}
#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


const bool multipleTestCases = false;

bool solve(){

    // int n;cin>>n;

    // if (n%3 == 0) print("Second");
    // else print("First");
    
    string s;cin>>s;
    
    // unique chars
    string unq;
    f(i,0,s.size()){
        if (unq.find(s[i]) == string::npos){
            unq+=s[i];
        }
    }
    /*
    a 12223334
    b 00111122
    c 00011111

    */
    map<char, vector<int>> freq;

    for(auto& c:unq){
        vector<int> counter(s.size());
        int j=0;
        f(i,0,s.size()){           
            if (s[i] == c) j++;

            counter[i] += j;
        }

        freq[c] = counter;
        // print(c, " - ", counter[s.size()-1]);
    }
    

    // _________ Queries
    int n;cin>>n;
    f(i,0,n){

        int a,b;
        char c;
        cin>> a>> b>> c;
        // print(a,b,">",c,"<");
        
        
        // print(freq[c][s.size()-1]);
        if (a==0){
            print(freq[c][b]);

        }
        else{

            print(freq[c][b] - freq[c][a-1]);
        }

    }
    

    print("finsihed");
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