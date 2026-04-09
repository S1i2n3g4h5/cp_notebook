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

    int x,y,dest_x,dest_y;cin>>x>>y>>dest_x>>dest_y;
 

    int elephant=0,camel=0,king=0;

    // Elephant
    if(x==dest_x or y==dest_y){
        elephant =1;
    }
    else 
        elephant = 2;

    // Camel
    if(((x+y)%2) == ((dest_x+dest_y)%2)){

        bool diagonal = abs(dest_y-y) == abs(dest_x - x);
        bool adiagonal = x+y == dest_x+dest_y;
        if(diagonal or adiagonal){
            camel = 1;
        }
        else{
            camel = 2;
        }

    }
    else{
        camel = 0;
    }

    // King
    king = max(abs(y-dest_y),abs(dest_x-x));


    print(elephant, camel, king);

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