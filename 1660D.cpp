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


    vector<int> prefix(n),suffix(n);
    prefix[0]=arr[0];
    f(i,1,n)prefix[i]=prefix[i-1]*arr[i];
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--) suffix[i] = suffix[i+1]*arr[i];


    // for(int i:prefix)cout << i << " ";
    // cout <<"\n";
    // for(int i:suffix)cout << i << " ";
    // cout <<"\n";

    int prefix_max = max_element(prefix.begin(), prefix.end()) - prefix.begin();
    int suffix_max = max_element(suffix.begin(), suffix.end()) - suffix.begin();
    
    if (prefix[prefix_max] <0 and suffix[suffix_max] < 0){
        // delete all to get product = 1   
        print(n-1, " 0..");  
    }
    else{
        int i,j;
        if(prefix[prefix_max] >= suffix[suffix_max]){
            i=0,j=n-1-prefix_max;
            // while(arr[i]!=0)i++;
            // while(arr[j]!=0)j--;
            
        }   
        else{
            // print(suffix_max-1, " 0");
            i=n-1-suffix_max,j=0;
            // while(arr[i]!=0)i++;
            // while(arr[j]!=0)j--;

        }

        print(i, " ", j);
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


