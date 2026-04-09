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
    vector<ll> arr(n);
    f(i,0,n)cin>>arr[i];


    auto mx_iter = max_element(arr.begin(), arr.end());
    ll mx_elem = *mx_iter;

    ll mns_available=0;
    f(i,0,n){
        if (arr[i] < mx_elem)mns_available++;
    }

    if (mns_available == 0){
        print(-1);
    }
    else{
        f(i,0,n){
            if (mx_elem != arr[i])continue;
            // bool left = i>1? arr[i-1] < mx_elem: false;
            // bool right = i+1<n? arr[i+1] < mx_elem: false;
            bool left = i==0?false : arr[i-1]<mx_elem;
            bool right = i==n-1 ? false : arr[i+1]<mx_elem;
            if (left or right){
                print(i+1);
                break;
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