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
    for k<=n its simple just output till kth beauty cuz each value beauty value is unique
    main case handling is for k>n like choosing distinct sum beauties.

    now the main logic is that, 
    first sort the array then choosing by creating paris, like 1 max and pair these with other elements
    then select 2 max and pair with other elements
    and so on..
    example -> 
        array = [a1,a2,a3,a4];  with sorted in increasing order
        first printing single elements 
        then printing ->    a4  a1
                            a4  a2
                            a4  a3
                            a4 a3  a1
                            a4 a3  a2
                            a4 a3 a2  a1

        Just make sure to stop once requred  k days data receieved.
        <<check constraints on k>>
    */

    int n,k;cin>>n>>k;
    vector<int>beauty(n);
    f(i,0,n)cin>>beauty[i];


    if (k<=n){
        f(i,0,k){
            print("1 ", beauty[i]);
        }
    }
    else{
        f(i,0,n){
            print("1 ", beauty[i]);
        }


        // choosing max strategy
        sort(beauty.begin(), beauty.end());
        
        
        int detachments = n;
        vector<int> curr_maxes = {beauty[n-1]};
        int j = n-2;

        while(detachments < k){
            for(int i=0;i<=n-curr_maxes.size()-1;i++){
                int curr_sz= 1 + curr_maxes.size();
                detachments++;
                
                cout << curr_sz << " " << beauty[i] << " ";
                
                for(auto p:curr_maxes){
                    cout << p << " ";
                }
                cout << "\n";


                if(detachments >= k){
                    break;
                }
            }
            curr_maxes.push_back(beauty[j--]);
        }
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
