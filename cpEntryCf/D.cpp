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
  

    long long n, k;
    cin >> n >> k;
    string s(n, 'a');
    

    ll low=1, high=n,len = 1;
    ll mid,mnt;

    while (low<=high) {
        mid = low + (high-low)/2;
        mnt = mid*(mid+1)/2;
        // print("mid:", mid, "    mnt:", mnt);    
        // print("low:", low, "    high:", high);  
        
        if (mnt>=k) {
            len=mid;
            high=mid-1;
            // high=mid;
        
        } 
        else 
            low=mid + 1;
            // high=mid-1;
    }
  
    // print(n-len, ", ", n-k, ", ", (len-1)*len/2);

    s[ n-len -1] = 'b';
    s[ n -k + ((len - 1) * len / 2)] = 'b';


    print(s);
    
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