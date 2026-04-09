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
    /*
    build a set<pair<ll,ll>> arr ={{1,x}} and 
    also creating "multiset<ll> gaps"
    now logic is as each query comes we divide it ->
    first apply upper_bound to find the upperlimit from in arr( o(logn) ) 
    then split it as follows by erasing curent element and 
    adding 2 new elements -> {st,x-1} and {x+1,end}

    but before adding we will check 
    if the new x-1 or x+1 pair is in blocked or not then onyl insert.
    and then looping on current arr to find the max len possible 
    */

    ll n,q;cin>>n>>q;

    set<pair<ll,ll>>arr = {{0,n}};
    multiset<ll>gaps = {n};

    while(q--){

        ll pos;cin>>pos;

        auto pos_iterator = arr.upper_bound({pos,2e18});
        pos_iterator--;
        auto it = *pos_iterator;


        ll L = it.first;
        ll R = it.second;
        
        arr.erase(it);
        arr.insert({L, pos});
        arr.insert({pos, R});
                
        gaps.erase(gaps.find(R - L));
        gaps.insert(pos - L);
        gaps.insert(R - pos);


        cout << *gaps.rbegin() << " ";
    }
    
    //generating subarray cpp 

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
