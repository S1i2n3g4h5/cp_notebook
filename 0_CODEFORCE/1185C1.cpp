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
    int n,m;cin>>n>>m;
    vector<int>times(n);
    f(i,0,n)cin>>times[i];

    int j=0;
    int currSum =times[0];
    int last_chr = 0;
    multiset<int> sortedarr;
    sortedarr.insert(times[0]);
    
    cout << "0 ";  // first person always passes exam;
    f(i,1,n){
        currSum += times[i];

        if (currSum <= m){
            cout << last_chr << " ";
            
        }else{
            // j=i-1;
            auto j_iter = sortedarr.end();
            j_iter--;
            int cnt =0;
            int tmp=currSum;
            while(currSum > m){
                
                // currSum = times[j];
                currSum -= (*j_iter);
                // j--;
                j_iter--;
                cnt++;
            }
            currSum = tmp;
            cout << cnt <<  " ";
            last_chr = cnt;
            // cout << i-j << " ";
            // last_chr = i-j;
            
            // while(currSum>m){
            //     currSum -= times[j];
            //     j++;
            // }
            // cout << j <<" ";
            // last_chr = j;
        }
        sortedarr.insert(times[i]);
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