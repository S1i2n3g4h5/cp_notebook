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



const bool multipleTestCases = 0;


void solve(){       
    int n,q;
    cin>>n>>q;

    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    ll tot=0ll;
    vector<ll>new_add(n);
    while(q--){
        ll typ;cin>>typ;

        if(typ == 1){
            ll v,x;cin>>v>>x;
            new_add[v-1]=tot;
        
            arr[v-1]=x;
        }
        else if(typ == 2){
            ll v;cin>>v;
        
            tot+=v;
        
        }
        else{
            ll q;cin>>q;
        
            print(arr[q-1] + (tot - new_add[q-1]));
        
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
