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
  int n,m;cin>>n>>m;
  vector<int>cust_max_price(m);
  multiset<int>ticket_price;
  f(i,0,n){
    int v;cin>>v;
    ticket_price.insert(v);
  }
  f(i,0,m)cin>>cust_max_price[i];
    

    // sort(ticket_price.begin(), ticket_price.end());
    f(i,0,m){
        
        // for(int j=n-1;j>=0;j--){
        //     if(ticket_price[j]<= cust_max_price[i] and !paid[j]){
        //         print(ticket_price[j]);
        //         paid[j]=1;
        //         found=1;
        //         break;
        //     }
        // }

        // auto elem = upper_bound(ticket_price.begin(), ticket_price.end(), cust_max_price[i]);
        auto elem = ticket_price.upper_bound(cust_max_price[i]);
        if(elem != ticket_price.begin()){
            
            --elem;
            print(*elem);
            ticket_price.erase(elem);
            
        }
        else{
            print(-1);
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