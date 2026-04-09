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
    first try with max prime num possible then once that exhausted, do buble sort like using primenumber 2;
    * repeating until the number isnt fixed on its original position index

    just fixing each position carefully until its not fixed 
    using binarysearch on prime numbers to get max possible jump as (2 is always the option)

    then swapping up to its original position
  */
    
    int n;cin>>n;
    vector<int>arr(n);
    f(i,0,n)cin>>arr[i];


    // seive
    bool primes_arr_bool[100000+2];
    fill(begin(primes_arr_bool), end(primes_arr_bool), true);
    primes_arr_bool[0] = primes_arr_bool[1] = false;    
    for(int i=2;i*i<=100000+2;i++){
        if(primes_arr_bool[i]){
            for(int j=i*i;j<=100000+2;j+=i){
                primes_arr_bool[j]=false;
            }
        }
    }
    vector<int>primes;
    f(i,2,100000+2){
        if(primes_arr_bool[i])
            primes.push_back(i);
    }
        

    vector<int>pos(n+1);
    f(i,0,n){
        pos[arr[i]] = i+1;
    }

    vector<pair<int,int>>out;
    f(i,1,n+1){
        int target_idx = i; 
        while(pos[i] != target_idx){
            int currpos = pos[i];
            int dist = currpos - target_idx + 1;

            // which prime number jump to take?
            int idx = upper_bound(primes.begin(), primes.end(), dist) - primes.begin();
            --idx;                      
            int jump = primes[idx];
            
            int swapidx = currpos - jump + 1;
            int curr_val = arr[currpos - 1];
            int dest_val = arr[swapidx - 1];

            swap(arr[currpos - 1], arr[swapidx - 1]);

            pos[dest_val] = currpos;
            pos[curr_val] = swapidx;


            out.push_back({min(currpos, swapidx), max(currpos, swapidx)});
        }

    }

    print(out.size());
    f(i,0,out.size()){
        print(out[i].first, " ", out[i].second);
    }


    
  
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
