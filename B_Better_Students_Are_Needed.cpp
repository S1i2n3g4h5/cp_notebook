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

    ll n;cin>>n;
    ll x,y,z;cin>>x>>y>>z;
    
    struct Score{
        int id;
        int eng;
        int math;
        int total;
        bool passed;

    };

    vector<Score>scores(n);
    // f(i,0,n)cin>>scores[i].math>>scores[i].eng,scores[i].id=i+1,scores[i].passed=false,scores[i].total = scores[i].math + scores[i].eng;
    f(i,0,n){
        cin>>scores[i].math;
    }
    f(i,0,n){
        cin>>scores[i].eng;
    }
    f(i,0,n){
        scores[i].passed=false;
        scores[i].total = scores[i].math + scores[i].eng;
        scores[i].id = i+1;
    }


    // FIRST
    sort(all(scores), [&](auto a,auto b){
        if(a.math != b.math){
            return a.math > b.math;
        }
        return a.id < b.id;
    });
    for(int i=0,count=0;i<n and count <x;i++){
        if(!scores[i].passed){
            scores[i].passed = true;
            count++;
        }
    }
    
    
    // SECOND
    sort(all(scores), [&](auto a,auto b){
        if(a.eng != b.eng){
            return a.eng > b.eng;
        }
        return a.id < b.id;
    });

    for(int i=0,count=0;i<n and count <y;i++){
        if(!scores[i].passed){
            scores[i].passed = true;
            count++;
        }
    }
    
    
    
    // THIRD
    sort(all(scores), [&](auto a,auto b){
        if((a.total) != (b.total))
            return (a.total) > (b.total);
    
        return a.id < b.id;
    });

    for(int i=0,count=0;i<n and count <z;i++){
        if(!scores[i].passed){
            scores[i].passed = true;
            count++;
        }
    }


    // printing
    vll admitted;
    f(i,0,n){
        if(scores[i].passed)
            admitted.pb(scores[i].id);
    }
    sort(all(admitted));

    f(i,0,admitted.size())
        print(admitted[i]);


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