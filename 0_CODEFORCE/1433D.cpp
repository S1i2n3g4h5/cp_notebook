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


void solve(){
    int n;cin>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];


    bool all_same = true;
    f(i,1,n){
        if(arr[i] != arr[0]){
            all_same = false;
            break;
        }
    }

    if (all_same){
        print("NO");
        
    }else{
        print("YES");

        
        int k=0;
        int j=-1;
        f(i,1,n){
            if (arr[i] != arr[k]){
                j = i;
                print(k+1 , " ", i+1);
            }
        }

        f(i,1,n){
            if (arr[i] == arr[k]){
                print(j+1, " ", i+1);
            }
        }
        
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