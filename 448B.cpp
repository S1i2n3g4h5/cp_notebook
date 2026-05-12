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
    automaton - deletion any char
    array - swapping 2 chars from a string s
    both - doing both operations

  */

    string s,t;cin>>s>>t;


    // is subsequence?
    int i=0,j=0;
    while(i<s.size() and j<t.size()){
        if(s[i] == t[j])j++;
        i++;
    }
    bool automaton = j == t.size();
    

    vll cnts(26,0), cntt(26,0);
    for(char c:s)cnts[c - 'a']++;
    for(char c:t)cntt[c - 'a']++;

    bool enough=true;
    f(i,0,26){
        if(cnts[i] < cntt[i]){
            enough=false;
            break;
        }
    }

    if(!enough){
        print("need tree");
    }
    else if(automaton){
        print("automaton");
    }
    else if(s.size() == t.size()){
        print("array");
    }
    else{
        print("both");
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