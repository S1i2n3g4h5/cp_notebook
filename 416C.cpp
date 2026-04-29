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
    we try putting the group to min able size so to have bigger space later


  */

    struct Group{
        int size,money,id;
    };
    struct Table{
        int capacity,id;
    };


    int n;cin>>n;
    vector<Group>arr(n);
    f(i,0,n){
        cin>>arr[i].size>>arr[i].money;
        arr[i].id = i+1;
    }
    int k;cin>>k;
    vector<Table>tables(k);
    f(i,0,k)cin>>tables[i].capacity,tables[i].id = i+1;


    sort(all(arr), [&](auto a, auto b){
        if(a.money != b.money)
            return a.money > b.money;
        return a.size < b.size;
    });


    sort(all(tables), [&](auto a, auto b){
        return a.capacity < b.capacity;
    });

    vector<pair<int,int>>assignments;
    vector<bool>table_occupied(k,false);

    ll tot=0,count=0;
    f(i,0,n){
        int best_table = -1;

        f(j,0,k){
            if(!table_occupied[j] and tables[j].capacity >= arr[i].size){
                best_table=j;
                break;
            }
        }

        if(best_table != -1){
            table_occupied[best_table] = 1;
            tot += arr[i].money;
            count++;
            
            assignments.pb({arr[i].id, tables[best_table].id});

        }

    }

    print(count ,tot);
    for(auto x:assignments){
        print(x.first, x.second);
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