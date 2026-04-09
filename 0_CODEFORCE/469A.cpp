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
    int a,b;cin>>a;
    vector<int>a1(a);
    f(i,0,a)cin>>a1[i];
    cin>>b;
    vector<int>a2(b);
    f(i,0,b)cin>>a2[i];


    vector<bool> pos(n+1,false);
    pos[0]=true;
    f(i,0,a)pos[a1[i]]=true;
    f(i,0,b)pos[a2[i]]=true;
  
  
    f(i,0,n+1){
        if(!pos[i]){
            print("Oh, my keyboard!");
            return;
        }
    }

    print("I become the guy.");
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