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
    
    ll n,m,h;cin>>n>>m>>h;
    vector<ll>arr(n);


    f(i,0,n)cin>>arr[i];

    vector<ll>orig = arr;
    vector<ll>history;
    

    while(m--){
        ll b,c;cin>>b>>c;
        b--;

        arr[b] += c;
        history.push_back(b);

        if(arr[b] > h){
            // arr = orig; //tooslow... 
            
            for(int idx:history){
                arr[idx] = orig[idx];
            }

            history.clear();
        }
    }


    f(i,0,n) 
        cout <<arr[i]<<" ";
    
    cout <<"\n";

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
