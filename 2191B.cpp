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
    int n;cin>>n;
    vector<int> arr(n);
    f(i,0,n)cin>>arr[i];
    
    
    sort(arr.begin(), arr.end());


    bool ys=1;
    f(i,0,n-1){
        int mex_prefix = 0;
        set<int> prefix_set;
        f(j,0,i+1) 
            prefix_set.insert(arr[j]);
        
        while(prefix_set.count(mex_prefix)){
            mex_prefix++;
        }


        set<int> suffix_set;
        f(j,i+1,n) suffix_set.insert(arr[j]);
        

        int mex_suffix = 0;
        while(suffix_set.count(mex_suffix)){
            mex_suffix++;
        }

        
        // print(mex_prefix, " - ", mex_suffix);

        if(mex_prefix == mex_suffix){
            ys=0;
            
            break;
        }
    }


    if (ys) print("YES");
    else print("NO");
    

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
