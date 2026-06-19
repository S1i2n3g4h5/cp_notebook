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
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
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

void solve(){
  /*
    so the intuition for this logic is like
    as we draw the balance vairable value for each bracket s[i]
    we find the minimum balance reached... 
    then because then we would know form that point onwards if i removed all opening brackt
    to its left and remove all closing brackets form its right then the answer will be 0
    cuz the closing braced will be more on left side cuz the balance got droppedn minimum there only we drew the partition
    < watch repovive video for more understanding >

    e.g
    1 2 1 0-1-2-1 0-1 0 1 0
    ( ( ) ) ) ) ( ( ) ( ( )


    so here the min partition we drwe is between (-2) and (-1) its next neibour
    cu if we removed all oopening brackets form left of -2, and all closing bracket from rihgt of -2
    the left stuff is - >  ))))((((
    Here its giving us the cost = 0;

    which is minimum possible which we wanted...

    So lets just implement this better idea... this is just too easy.
    < we will ignore this long implementaion >
    
  */

    ll n,k;cin>>n>>k;
    string s;cin>>s;


    // selecting the partition index
    ll mn=0,b=0,idx=0;
    f(i,0,n){
        b += (s[i] == '(' ? 1 : -1);
        if(b < mn){
            mn = b;
            idx = i+1;
        }
    }


    // do the partition
    string res(n,'0');
    for(int i=0;i<n and k>0;i++){
        if((i < idx and s[i] == '(') or (i >= idx and s[i] == ')')){
            res[i] = '1';
            k--;
        }
    }

    cout << res << "\n";

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