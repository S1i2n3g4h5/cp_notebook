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
    
  int k,n;cin>>k>>n;
  vector<string>arr(k);
    bool valid=1;
  f(i,0,k){
    cin>>arr[i];
    int cnt1=0;
    f(j,0,n) cnt1 += (arr[i][j] == '1'? 1 : 0);
  
    if(cnt1 == 0)
        valid=0;
  }

  if(!valid){
    print(-1);
    return;
  }
  

    vector<vector<int>>dist_mat;
    f(i,0,k){

        vector<int>ones;
        f(j,0,n){
            if(arr[i][j] == '1')
                ones.push_back(j);
        }

        int sz = ones.size();
        f(j,0,sz){
            ones.push_back(ones[j] - n);
            ones.push_back(ones[j] + n);
        }

        sort(ones.begin(), ones.end());

        vector<int>pos(n);
        f(j,0,n){
            auto it = lower_bound(ones.begin(), ones.end(), j);

            pos[j] = min((*it - j), (j - *prev(it)));
        }

        dist_mat.push_back(pos);
    }


    int mn=n*n;
    f(j,0,n){
        int sm=0;
        f(i,0,k){
            sm += dist_mat[i][j];
        }
        mn=min(mn,sm);
    }

    print(mn);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
