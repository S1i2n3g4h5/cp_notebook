#include <bits/stdc++.h>
using namespace std;

#define debug(...) \
    std::cerr << #__VA_ARGS__ << "  =  "; \
    _print_debug(std::cerr, __VA_ARGS__); \
    std::cerr << std::endl;
template <typename T>
void _print_debug(std::ostream& os, const T& arg) {os << arg;}
template <typename T, typename... Args>
void _print_debug(std::ostream& os, const T& arg, const Args&... args) {os << arg << "  ";_print_debug(os, args...);}    


#define fll(i, a, b)          for(ll i = a; i < b; i++)
#define f(i, a, b)          for(int i = a; i < b; i++)
#define fr(i, a, b)          for(int i = a; i > b; i--)

#define ll long long
#define yes std::cout << "YES";  
#define no std::cout << "NO";  

 
bool solve(){
  int n;
  cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j <= 2 * (n - i); ++j)
        {
            cout << ' ';
        }
        for (int j = 0; j < i; ++j)
        {
            cout << j << ' ';
        }
        for (int j = i; j >= 0; --j)
        {
            cout << j;
            if (j)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 1; j <= 2 * (n - i); ++j)
        {
            cout << ' ';
        }
        for (int j = 0; j < i; ++j)
        {
            cout << j << ' ';
        }
        for (int j = i; j >= 0; --j)
        {
            cout << j;
            if (j)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

  
  
  return 1;
}
 
int main() {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

    
    int t;
    // cin >> t;
    t=1;
    while(t--){
    
      
      solve();
      
      cout << endl;
      
   
        
      // ______________________________________________________  
      // ______________________________________________________
        
        
         
        // _______________________________________________________
        // _______-  hackerrank largest prime number (deque for max in sliding window not o(n))
        // _______________________________________________________
        
        // int n, k;
        // cin >> n >> k;
        
        // vector<int> arr(n);
        // for (int i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }
        
        
        
        // // -------- DEQUE ---------
        // deque<int> dq;
        // for (int i = 0; i < n; ++i) {
        //     // FRONT CLEARING
        //     while (!dq.empty() && dq.front() <= i - k) {
        //         dq.pop_front();
        //     }

        //     // BACK CLEARING
        //     while (!dq.empty() && arr[i] >= arr[dq.at(dq.size() - 1)]) 
        //     { 
        //         dq.pop_back();
        //     }
            
        //     dq.push_back(i);

            
        //     if (i >= k - 1) {
        //         cout << arr[dq.front()] << " ";
        //     }
        // }
        
        // cout << endl;
        
          
        // ______________________________________________________
        // *******  codeforces.com/contest/116/problem/D
        // ______________________________________________________
        
        
            
        
        
        
      }
    
    return 0;
}   


#pragma GCC optimize("O2")  
