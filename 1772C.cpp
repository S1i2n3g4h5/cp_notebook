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
    int k,n;cin>>k>>n;

    
    int diff=1;
    vector<int>a={1};

    f(i,1,k){
        if(a.back()+diff+k-i-1 <= n){
            a.push_back(a.back() + diff);
            diff++;
        } 
        else{
            a.push_back(a.back() + 1);
        }
    }

    for(int i:a){
        cout << i << " ";

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


