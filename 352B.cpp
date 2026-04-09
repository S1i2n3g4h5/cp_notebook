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
  vector<int>arr(n);
  f(i,0,n)cin>>arr[i];


    map<int,vector<int>> positions;
    f(i,0,n){
        positions[arr[i]].push_back(i);
    }

    vector<pair<int,int>> res;
    for(auto [num, poses] : positions){

        if(poses.size() == 1){
            res.push_back({num, 0});
        }
        else{
            // Check AP
            int a=poses[0];
            int d=poses[1] - a;

            bool valid=1;
            f(i,1,poses.size()){
                if(poses[i] - poses[i-1] != d){
                    valid=0;
                    break;
                }
            }
            if(valid)
                res.push_back({num, d});
        }
    }

    sort(res.begin(), res.end());

    print(res.size());
    for(auto [x,y]:res){
        print(x, " ",y);
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
