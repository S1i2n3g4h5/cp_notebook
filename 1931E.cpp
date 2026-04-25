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

void solve(){
  /*
    basicly this 10^m is just how many total digits it got

    seems like counting problem mostly
    anna -> reverse digits (powerto remove triling zeros hence reducting digit count)
    sasha -> joins 2 numbers

    anna wasnts the final number of digits to be small

    so asically we can countin total digit and its trailing zoeres and hence
    anna chooses 1st,3rd... odd index
    shsaho chooses 2nd,4th et...even index


   ->  and evne if sasha chooses 2 digits with trailing digits it doesnt help
    cuz this way the zeroes are still endangered to anna whcih she can reverse and still makiing the big nuber small again


  */

    ll n,m;cin>>n>>m;
    vector<string> a(n);
    f(i,0,n)cin>>a[i];


    ll tot_digits=0;
    vll zeroes;
    f(i,0,n){
        tot_digits += a[i].size();

        int trailing=0;
        for(int j=a[i].size()-1;j>=0;j--){
            if(a[i][j] == '0')trailing++;
            else break;
        }

        zeroes.pb(trailing);
    }

    sort(rall(zeroes));


    // anna taking these digits
    ll deleted = 0;
    for(int i=0;i<zeroes.size();i+=2){
        deleted += zeroes[i];
    }


    if(tot_digits - deleted >= m+1){
        print("Sasha");
    }
    else
        print("Anna");

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