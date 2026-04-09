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

    since sorting is key here, to sort with least start and max end time, we cna rapidly check the guys under it
    
  */

    struct Range{
        ll start,end;
        ll idx;
    };


    int n;cin>>n;
    vector<Range>range(n);
    f(i,0,n){
        cin>>range[i].start>>range[i].end;
        range[i].idx = i;
    }

    sort(all(range), [&](auto a,auto b){
        if(a.start == b.start)
            return a.end > b.end;
        return a.start < b.start;
    });


    vector<int> contains(n,0), contained(n,0);


    // Contains...
    ll mn=2e9;
    for(int i=n-1;i>=0;i--){
        if( range[i].end >= mn){
            contains[range[i].idx] = 1;
        }

        mn = min(mn, range[i].end);
    }


    // Contained
    ll mx=0;
    f(i,0,n){
        if(range[i].end <= mx){
            contained[range[i].idx] = 1;
        }

        mx = max(mx, range[i].end);
    }


    f(i,0,n)cout << contains[i] << " ";
    cout <<"\n";
    f(i,0,n)cout << contained[i] << " ";
    cout <<"\n";

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