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



const bool multipleTestCases = false;

bool solve(){
    ll n,k;cin>>n>>k;

    ll l,h,mid;
    l=0;
    h=n;
    
    while(l<=h){
        mid = l + (h-l)/2;
        
        /*
        n-k   for suming upp find suitable x;
        n*(n+1)/2  - totals

        then just gota find the leftout ->    (n-currCandies)*(n-currCandies+1)/2  - currCandies

        will be req to loop [0,n] then only find the suitabl leftover till its == k (given);

        */
        ll candies = ((n-mid)*(n-mid+1)/2) - mid; 
        
        if (candies == k){
            break;
        }
        
        if (candies > k){
            l=mid+1;
        }
        else if (candies < k){
            h=mid-1;
        }
    

    }
    print(mid);

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