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

    string t,p;cin>>t>>p;
    vector<int>deletions(t.size());
    f(i,0,t.size())cin>>deletions[i];


    auto check = [&](ll del){

        // string new_str="";
        // f(i,del, t.size()){
        //     new_str.push_back(t[deletions[i] - 1]);
        // }

        // return new_str.find(p) != string::npos;

        vector<bool> is_deleted(t.size(),false);
        f(i,0,del){
            is_deleted[deletions[i] -1] = true;
        }

        int p_ptr = 0;
        f(i,0,t.size()){
            if(!is_deleted[i]  and t[i] == p[p_ptr]){
                p_ptr++;
            }

            if(p_ptr == p.size())
                return true;
        }

        return false;
        
    };

    ll l=0,h=t.size();
    while(l<=h){
        ll mid = l + (h-l)/2;

        if(check(mid)){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    print(l-1);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
