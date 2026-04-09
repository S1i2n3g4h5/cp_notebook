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




const bool multipleTestCases = true;




bool solve(){
    int n,k;cin>>n>>k;
    vector<ll> arr(n);
    map<ll, int> freq;
    f(i,0,n){
        cin>>arr[i];
        freq[arr[i]]++;
    }
  
    // Check if -1?
    int valid = 0;
    vector<ll> valids;
    for(auto& p:freq){
        if (p.second >= k){
            f(i,0,k)valids.push_back(p.first);
            valid++;
        }
    }
    
    if (valid == 0){
        print(-1);
        return 1;
    }

    
    sort(valids.begin(), valids.end());
    int newlen = valids.size();
    
    int i=0, j=1;
    while(j<newlen){
        if (valids[j] - valids[j-1] >= 2){
            i=j;
        }
        j++;
    }

    print(valids[i], " ", valids[j]);

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