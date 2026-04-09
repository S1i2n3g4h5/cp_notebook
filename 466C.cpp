/*
  Competing against Myself  
  [zoASHro]
*/
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
const bool multipleTestCases = 0;


void solve(){
  /*

  */
 int n;cin>>n;
 vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];

    // //prefix
    // vector<ll>pf(n);
    // pf[0] =arr[0];
    // f(i,1,n)
    //     pf[i] = arr[i] + pf[i-1];
    
    
    // // main case
    // ll tot = pf[n-1];
    // if(tot%3 != 0){
    //     print("0");
    //     return;
    // }


    // ll ans=0ll;
    // ll curr_cnt=0ll;
    // ll target = tot / 3;
    // f(i,0,n-1){
    //     // second cut possible??
    //     if(i>=1 and i<=n-2 and pf[i] == 2*target){
    //         ans += curr_cnt;
    //     }        

    //     // first cut along with limit
    //     if(i<=n-3 and pf[i] == target){
    //         curr_cnt++;
    //     }
    // }

    // print(ans);




    // _____________________________________
    // _____ APPLYING BINARY SEARCH METHOD
    // _____________________________________


        
    
    // main case
    ll tot = accumulate(arr.begin(), arr.end(), 0ll);
    if(tot%3 != 0){
        print("0");
        return;
    }


    ll ans=0ll;
    ll pf=0ll;
    ll target = tot / 3;
    
    vector<ll>set_1,set_2;
    f(i,0,n-1){
        pf += arr[i];
        
        // set 1
        if(i<=n-3 and pf == target){
            set_1.push_back(i);
        }

        // set 2
        if(i>=1 and i<=n-2 and pf==2*target){
            set_2.push_back(i);
        }

    }



    // apply binary search for finding the possible paris available
    f(i,0,set_2.size()){

        auto it = lower_bound(set_1.begin(), set_1.end(), set_2[i]);

        ans += distance(set_1.begin(), it);
    }

    print(ans);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
