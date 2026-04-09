/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 



void solve(){
  /*
    since its pure implementation -
        monocarp - queue
        poly - max priority

    but if need to remove after typ 2 from poly set then its time incr

    so to keep the connection of customer serving between both, we just need to make sure both are connected correctly

  */

    int q;cin>>q;

    struct Customer{
        int id,money;
    };
    struct PolyCompare{
        bool operator()(const Customer &a, const Customer& b) const{
            if(a.money == b.money) 
                return a.id < b.id;
            return a.money > b.money;
        }
    };

    set<Customer,PolyCompare> poly;
    vector<int>served(500000,false);
    int currid =1;
    int mono=1;


    while(q--){
        int t;cin>>t;

        if(t == 1){
            int m;cin>>m;
            poly.insert({currid++, m});
        }
        else if(t == 2){
            while(served[mono]) mono++;

            cout << mono << " ";
            served[mono] = true;
        }
        else{
            // poly rem;
            while(!poly.empty() and served[poly.begin()->id]){
                poly.erase(poly.begin());
            }

            auto top=poly.begin();
            cout << top->id << " ";
            served[top->id]=true;
            poly.erase(top);
        }


    }
    cout << "\n";

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}