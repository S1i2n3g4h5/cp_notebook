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


const bool multipleTestCases = 1; 

void solve(){
  /*
    similar numbers if-
        - same parity when devided by 2 like even evne  or odd odd
        - adjacent numbers

    constrints and are very small, meaning o(n^2) might be the boundary

    lets counting the parity of even,odds for this...
    
    

  */

    int n;cin>>n;
    vll arr(n);
    f(i,0,n)cin>>arr[i];


    int odd_parity = 0, even_parity = 0;
    f(i,0,n){
        if(arr[i]%2==0) even_parity++;
        else odd_parity++;
    }


    if(odd_parity%2==0 and even_parity%2==0){
        print("YES");
        return;
    }
    else if(odd_parity%2==1 and even_parity%2==1){
        // Look for atleast 1 adjacent elemnt to fix the odd counts
        set<int> to_find;
        f(i,0,n){

            if(to_find.count(arr[i]) > 0){
                print("YES");
                return;
            }

            to_find.insert(arr[i]-1);
            to_find.insert(arr[i]+1);

        }
    }
    
    print("NO");


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