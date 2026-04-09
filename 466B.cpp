/*
  Competing against Myself  
  [zoASHro]
*/
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
        since the constraints given based on 6n  its easily to do the sqrt trick here
        looping var a till that max value possible and then var b easily found. 
        Since the area required is needded >= 6n, this method works;


        * make sure to check if var b1 is not less than b cuz we can only expand and no shrinking of room size;
  */

  ll n,a,b;cin>>n>>a>>b;

  n=(6ll * n);
  ll constraint = sqrt(n);
    
 
    //need to swap later **
  bool swp_later=0;
  if(a>b){
    swap(a,b);
    swp_later=1;
    }
  

    ll bst_size =2e19;
    ll bst_a=a,bst_b=b;
    
    
    if(a*b >= n){
        bst_size = a*b;
    }        
    

    f(a1,a,constraint + 1ll){

        ll b1 = (n +a1 - 1)/a1;
        b1 = max(b1,b); 
    
        // print(a1*b1);
        if(a1*b1 < bst_size){
            bst_size = a1*b1;
            bst_a = a1;
            bst_b = b1;
        }
    }


    print(bst_size);
    
    if(swp_later){
        print(bst_b, " ", bst_a);  
        
    }
    else{
        print(bst_a, " ", bst_b);  
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
