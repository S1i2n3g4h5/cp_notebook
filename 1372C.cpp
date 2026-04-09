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

    Possible answer will always be either 0,1,2
    0-> when all sorted
    1-> if no correct position number like all scrambled
    2-> if any 1 number at correct position


    extra precaution, -> make sure to trim the correct position from both left andd right as to avoid getting them scrambledd
    this is important observation here..

  */

    int n;cin>>n;
    vll a(n);
    f(i,0,n)cin>>a[i];


    if(is_sorted(all(a)))
        print(0);
    else{

        int l=0,r=n-1;
        while(l<n and a[l] == l+1) l++;
        while(r>=0 and a[r] == r+1) r--;


        bool correct_pos = 0;
        f(i,l,r+1){
            if(i+1 == a[i]){
                correct_pos = 1;
                break;
            }
        }

        if(correct_pos){
            print(2);
        }
        else{
            print(1);
        }

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