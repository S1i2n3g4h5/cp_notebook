/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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

  */

    string myname;cin>>myname;
    int n;cin>>n;

    map<string,ll>scores;

    f(i,0,n){
        string name1,action,temp,name2;
        cin>>name1>>action;

        int points=0;
        if(action == "posted"){
            cin>>temp;
            points = 15;
        }
        else if(action == "commented"){
            cin>>temp;
            points = 10;
        }
        else{
            points = 5;
        }


        cin >> name2;
        name2 = name2.substr(0, name2.size() - 2);
        
        string trash;cin>>trash;

        if(name1 != myname) scores[name1] += 0;
        if(name2 != myname) scores[name2] +=0;


        if(name1 == myname){
            scores[name2] += points;
        }
        else if(name2 == myname){
            scores[name1] += points;
        }

    }

    vector<pair<string,int>> res(all(scores));
    sort(all(res), [&](auto p1, auto p2){
        if(p1.second != p2.second){
            return p1.second > p2.second;
        }
        return p1.first< p2.first;
    });


    for(auto p:res){
        print(p.first);
    }

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
/*

}*/