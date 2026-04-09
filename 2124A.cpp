#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 1;

void solve(){
  /*

  */
 
    int n;cin>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];


    // f(i,0,n){
    //     f(j,i+1,n){
    //         if(arr[i] > arr[j]){
    //             print("YES");
    //             print("2");
    //             print(arr[i], " ", arr[j]);
    //             return;
    //         }
    //     }
    // }
    
    // print("NO");


    // _________________________________

    vector<int>ans(n), b(n);
    f(i,0,n)b[i]=arr[i];
    sort(b.begin(), b.end());
    
    int k=0;
    bool found=false;
    f(i,0,n){
        if(arr[i] != b[i]){
            ans[k++] = arr[i];
            found=1;
        }
    }

    if(found){
        print("YES");
        print(k);
        f(i,0,k)
            cout << ans[i] << " ";
        cout << "\n";
    }
    else{
        print("NO");
    }

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
