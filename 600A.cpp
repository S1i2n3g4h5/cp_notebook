/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
    this i spure implementaion but need to handle the edge cases correctly

    make sure to add `;` as last to take the last word as well into the consideration when checking

    empty word edge case
  */

    string s;cin>>s;
    s+=',';


    auto is_num = [&](string t){
        if(t.empty()) 
            return false;
    
        for(char c:t){
            if(c < '0' or c>'9')
                return false;
        }
        if(t.size() > 1 and t[0] == '0')
            return false;

        return true;    
    };


    vector<string>a,b;
    string current="";

    for(char c:s){
        if(c == ',' or c==';'){
            // print("- >", current);

            if(is_num(current)){
                a.push_back(current);
            }
            else
                b.push_back(current);

            current = "";
        }
        else{
            current += c;
        }
    }


    // valid ones printing
    if(a.empty()) cout << "-";
    else{
        cout << "\"";
        f(i,0,a.size()){
            cout << a[i] << (i+1==a.size() ? "" : ",");
        }
        cout<<"\"";
    }
    cout <<"\n";

    
    // invalid ones printing
    if(b.empty()) cout << "-";
    else{
        cout<<"\"";
        f(i,0,b.size()){
            cout << b[i] << (i+1==b.size() ? "" : ",");
        }
        cout<<"\"";
    }
    cout <<"\n";

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