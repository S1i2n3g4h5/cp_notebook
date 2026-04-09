/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

void print() { cout << "\n"; }
template <typename T, typename... Args>
void print(T first, Args... args) { cout << first << (sizeof...(args) ? " " : ""); print(args...); }

#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const bool multipleTestCases = 1; 

void solve(){
    /*
    Disjoint Set (Venn Diagram) Approach:
    We categorize every visiting day into unique, non-overlapping groups.
    */

    ll a,b,c,m;cin>>a>>b>>c>>m;

    auto lcm = [&](ll x,ll y){
        return (x/__gcd(x, y))*y;
    };


    ll ans1,ans2,ans3;

    ll nA = m/a, nB=m/b,  nC=m/c;
    ll nABC = m/lcm(a,lcm(b,c));
    // print(nA, nB, nC, nABC);

    ll nAB = m/lcm(a,b);
    ll nAC = m/lcm(a,c);
    ll nBC = m/lcm(b,c);

    // print(nAB*a/m)
    ll onlyAB = nAB - nABC;
    ll onlyAC = nAC - nABC;
    ll onlyBC = nBC - nABC;

    

    // set disjoint
    ll onlyA = nA - (onlyAB + onlyAC + nABC);
    ll onlyB = nB - (onlyAB + onlyBC + nABC);
    ll onlyC = nC - (onlyAC + onlyBC + nABC);


    // disjoing grps ..
    ll ansA = (onlyA *6) + (onlyAB + onlyAC)*3;
    ll ansB = (onlyB*6) + (onlyAB +onlyBC)*3;
    ll ansC = (onlyC*6) + (onlyAC+ onlyBC)*3;


    print(ansA+nABC*2, ansB+nABC*2, ansC+nABC*2);
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