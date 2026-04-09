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


void solve(){       
    
    int n,m,k;cin>>n>>m>>k;
    vector<ll>a(n),b(m);
    f(i,0,n)cin>>a[i];
    f(i,0,m)cin>>b[i];
    
    string gdCode;cin>>gdCode;

    
    sort(b.begin(), b.end());

    vector<vector<int>> die_right(k + 1), die_left(k + 1);

    f(i,0,n) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        
        if (it != b.end()) {
            ll dist = *it - a[i];
            if (dist <= k) {
                die_right[dist].push_back(i);
            }
        }
        
        if (it != b.begin()) {
            ll dist = a[i] - *prev(it);
            if (dist <= k) {
                die_left[dist].push_back(i);
            }
        }
    }

    
    vector<bool>dead(n,0);
    int alive = n;
    int cur = 0;
    int max_r = 0;
    int max_l = 0;

    f(i, 0, k) {
        if(gdCode[i] == 'R'){
            cur++;
        } 
        else{
            cur--;
        }

        if(cur > max_r){
            max_r = cur;
            if(max_r <= k){
                for(int idx : die_right[max_r]){
                    if(!dead[idx]){
                        dead[idx] = true;
                        alive--;
                    }
                }
            }
        }

        if(cur < -max_l){
            max_l = -cur;
            if(max_l <= k){
                for(int idx : die_left[max_l]){
                    if(!dead[idx]){
                        dead[idx] = true;
                        alive--;
                    }
                }
            }
        }
        
        cout << alive << (i == k - 1 ? "" : " ");
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
