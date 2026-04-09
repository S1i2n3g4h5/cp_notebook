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

// bool check_div_array(auto arr){
//     f(i,2,arr.size()){
//         if((3*arr[i]) % (arr[i-2]+arr[i-1]) == 0){
//             return true;
//         }
//     }
//     return false;
// }

void solve(){       

    ll n;cin>>n;
    
    vector<ll>arr;
    ll out=1ll;
    f(i,1,n+1){
        cout << out << " ";
        out+=2;
    }


    cout << "\n";
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
