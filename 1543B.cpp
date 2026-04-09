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
    the elements need to be as close to eahc other in array for reducing the sum of diffs of pairs

    <Never just assume whats presented is all information>
    like here instead of moving all blocks of cars from lane1 to lane2, we can just remove 1 car from lane1 and shift to lane2

    so this means we got full flexibility onto the sum,div or anything to do

    "reading each line of question is very important so you not miss the line which leads to hitns and answer correctly
like here for reading few times I missed the line ""choose a traffic car and move it""   which was was key to buildig the solution for this quesiton. 
this is pretty simple using brute force implementaion but due to not paying attention got drowled down with no solution appraoch.      
but as soon as it came got like yes we can shift any car anywhwere and no restrcition so we just try shifting the cars such that its evenly divided across all lanes which results into min inconveience possible, and its optimal too.   just dry run if not believing  :) 
also evne if you thouh to dividing inot 2 lanes but stil while calcuating the incvonectine the answer will be larger here cuz the answer inceonveience is not jsut for 2 lanes for all n lanes where these 2 special lanes included as well"


    since the question asked for all possible pairs summs diff, we just return it
    that all possible sets having these diffs - total pairs = k*(n-k)
        k = S/n +1    

  */

    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];


    ll sm = accumulate(all(a), 0ll);

    ll k = sm % n;

    // best result is k*(n-k)   cuz k tracks with (avg+1) cars
    // and n-k tracks with (avg) cars. so every pair between these 2 groups contribute exactly 1 to the sum;

    print(k*(n-k));

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