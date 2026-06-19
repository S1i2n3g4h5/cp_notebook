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

// Boost Multiprecision (rare but lifesaving)
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// int128_t  : when ll overflows (products > 1e18)
// int256_t/int512_t/int1024_t : fixed ultra-large integers
// cpp_int : arbitrary precision integer, ideal for n! , Catalan numbers, huge DP counts


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
    goal is to find n distinct perfect squares fo length n
    that are all anagrams of each other.

    given n -> alwyas ODD

    BRUTE force cant work cuz, for n=99, there are 2*10^99 nubers...
    hence it exploeded....

    - - - - - - - - - -

    since we need to get n-length digits
    we can just utilize the number like 13x13=169

    and padding gives us consstent results...

    like for n=5,
    103^2 = 90601 (5 digit)
    but if ew pad too much ->  1003^2 = 1006009 (length 7)

    hence this kind of variation we get->

    FOR N=5
        1. max internal gap - 1 0 6 0 9
        2. mirror of 1st    - 9 0 6 0 1
        3. close internal gap, push eroes to end - 16900  (130^2)
        4. mirror of above - 96100 (310^2)
        5. another arrangement for {1,6,9} digits can be  -  19600 (140^2)


    similarly for n=7,
    we can just try combinations of putting zeroes->
        1690000, 1060900, 1006009
    
        and since choosing internal gap size from 0 up to (n-1)/2


    ------

    hence the core strategy is that,
    we pad the zeroes wiht i-1 to n/2-1
    for forward + bacward iteration  +  singe 196<zeroes>




  */

    ll n;cin>>n;

    if(n==1){
        cout << 1 << "\n";
        return;
    }



    ll variation = n/2;
    

    vector<string>arr;


    // forward
    f(i,0,variation){
        string s = "1";
        s += string(i,'0');

        s += "6";
        s += string(i,'0');
        
        s += "9";
        s += string(n-s.size(),'0');

        arr.push_back(s);
    }
    
    // backward
    f(i,0,variation){
        string s = "9";
        s += string(i,'0');

        s += "6";
        s += string(i,'0');
        
        s += "1";
        s += string(n-s.size(),'0');

        arr.push_back(s);
    }
    
    string base = "196";
    base += string(n - base.size(), '0');
    arr.push_back(base);




    f(i,0,n){
        cout << arr[i] << "\n";
    }




    // // __________-------------____________-------------___________-------------___________
    // //      BRUTE FORCE  FINDING THE N-SIZED ANAGRAM SQURED CLUSTER
    // // __________-------------____________-------------___________-------------___________

    // ll min_val = 1;
    // // f(i,0,n-1){
    // //     min_val *= 10;
    // // }

    // ll max_val = 100000000;//(min_val*10)-1;

    // ll start_root = ceil(sqrt(min_val));
    // ll end_root = ceil(sqrt(max_val));


    // map<string,vll>clusters;
    // f(r,start_root,end_root+1){
    //     ll sq = r*r;
    //     string square_str = to_string(sq);
    
    //     string signature = square_str;
    //     sort(all(signature));

    //     clusters[signature].push_back(sq);
    // }




    // // finding the cluster to match the size N
    // ll found=false;
    // for(auto [signature,square_list]:clusters){
    //     if(square_list.size() == n){
    //         found=true;
    //         // cout << "Found a valid cluster of size " << n << "!\n";
    //         // for (auto sq : square_list) {
    //         //     // cout << sqrt(sq) << " - "<<  sq << "\n";
    //         //     cout << sq <<"\n";
    //         // }
    //         cout << signature <<"\n";
    //         cout << "\n\n";

    //     }
    // }

    // // if (!found) {
    // //     cout << "No standalone cluster of size exactly " << n << " was found via raw search.\n\n";
    // // }

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