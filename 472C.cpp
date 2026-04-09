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

  */

    int n;cin>>n;
    vector<pair<string,string>>handles(n);
    f(i,0,n)cin>>handles[i].first >>handles[i].second;
    vector<int>order(n);
    f(i,0,n)cin>>order[i];

    string last_string="";

    f(i,0,n){
        auto fullname = handles[order[i]-1];
        string first_name = fullname.first;
        string last_name = fullname.second;

        if(first_name > last_name) swap(first_name, last_name);

        if(last_string.empty()){
            last_string = first_name;
        }
        else{
            if(last_string >= first_name and last_string >= last_name){
                print("NO");
                return;
            }

            if(last_name < first_name)
                last_string = first_name;
            else
                last_string = last_name;

        }

    }


    print("YES");

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