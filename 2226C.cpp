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


const bool multipleTestCases = 1; 

bool check(ll k, vll&arr){
    multiset<ll>s(all(arr));

    for(ll x=k-1;x>=0;x--){
        auto it = s.find(x);
        if(it!= s.end()){
            s.erase(it);
        }
        else{
            auto it = s.upper_bound(2*x);

            if(it == s.end()){
                auto last = s.rbegin();
                if(last != s.rend() and *last > 2*x){
                    s.erase(prev(s.end()));
                }

                else{
                    return false;
                }
            }
            else{
                s.erase(prev(s.end()));
            }

        }
        
    }
    return true;
}

void solve(){
  /*
    1. we just have to find the max possibel mex and max mex is just the size of array
    2. we are able to chose any bi values for each wth which we want it to divide and leave som remainder
    3. for makng it easy we can sort the array and find current mex and check if its alreay max or not
    4. if not then, we try to include 0,1,2,3... by ensureing that most values come, 
       like i found that for any x, we find its reamnder 0,1,2..n-1 x%(x-1) , x%(x-2)... x%(x//2)

    till this range we get unique remainders with which we cna verify 
    if the curernt number hsould be put as it is or divided till which mex this is very usefu prperlty i verifieed myself
  

    using ouor half-mod theory, the equatino to verify becomes-
        2*r + 1 <= x

    r is the remainder and x is the number

    -------


    beter strategy would be to use binary search on anser for K(the mex)


  */


    ll n;cin>>n;
    vll arr(n);
    map<ll,int>mp;
    f(i,0,n){
        cin>>arr[i];
        mp[arr[i]]++;   
    }


    ll low=0,high=n;
    ll ans=n;
    while(low<=high){
        ll mid = low + (high-low)/2;

        if(check(mid, arr)){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }


    print(ans);

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