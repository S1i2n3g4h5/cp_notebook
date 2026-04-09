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

    int n,k;cin>>n>>k;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];


    int l=0,r=0;
    map<int,int>freq;
    // freq[arr[0]] = 1;

    int distinct_count =0;
    while(l<=r and r<n){
        
        // add new elem
        if(distinct_count < k){
            if(freq[arr[r]] <=0){
                distinct_count++;
            }

            freq[arr[r]]++;
        }


        if(distinct_count == k){
            // Found now shrinking . . .

            while(freq[arr[l]] >=2){
                
                freq[arr[l]]--;   
                l++;
            }

            print(l+1, " ", r+1);
            return;
        }

        r++;
    }

    print("-1 -1");

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
