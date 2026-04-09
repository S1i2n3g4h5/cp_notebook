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

int bl=0;
int br=0;

void expand(const string &s, int l, int r){


}


bool solve(){
    string s;
    cin>> s;
    int n = s.size();

    int a_cnt = 0;
    int b_cnt = 0;
    f(i,0,n){
        if (s[i]  == 'a')a_cnt++;
        else b_cnt++;
    }

    /*
    aaaaaaaa
    bbbbbb        6
    aaabbbbbaaaaa     s.size()

    bbbaaaabbbb      4
    ababa    3 
    ababab   3
    
    */

    // int i=0;
    // int j=s.size()-1;

    // while(s[i] != 'a')i++;
    // while(s[j] != 'b')j--;

    // // print(i,",",j);
    // print(j-i+1);


    f(i,0,n){

        expand(s,i,i);
        // expand(s, i,i+1);

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