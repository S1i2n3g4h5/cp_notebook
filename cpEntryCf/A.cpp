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

    int n, m;
        cin >> n >> m;
        
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        
        vector<int> ans(n + 1, -1);
    
        unordered_set<int> exsts;
        for (int i = 1; i <= n; i++) {
            exsts.insert(i);
        }
        

        list<int> field;
        unordered_map<int, list<int>::iterator> pos;

        for (int i=1;i<=n;i++) {
            field.push_back(i);
            pos[i] = prev(field.end());
        }
        

        for (int t=1;t<=m;t++) {
            
            
            if (exsts.count(p[t - 1])) {
                field.erase(pos[p[t - 1]]);
                field.push_front(p[t - 1]);
                
                pos[p[t - 1]] = field.begin();

            } 
            else {
            
                int removed = field.back();
                field.pop_back();
                pos.erase(removed);
                
            
                if (removed <= n && ans[removed] == -1) {
                    ans[removed] = t;
                
                }
                
            
                exsts.erase(removed);
                exsts.insert(p[t - 1]);
                
                field.push_front(p[t - 1]);
                
                pos[p[t - 1]] = field.begin();
            }
        }
    
        


    f(i,1,n+1)cout << ans[i] << " ";
    cout << endl;

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