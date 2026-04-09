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


void fall(int r, int c, int&n, auto&mat){
    // recursive falling
    if(r+1 >= n) return;

    if(mat[r+1][c] == 'o' or mat[r+1][c] == '*') return;

    swap(mat[r][c], mat[r+1][c]);
    fall(r+1, c, n, mat);
}

void solve(){
  /*
    brute force implementation easily done

    but lets try doing it recursively through recursion :) as a challenge

  */

    int n,m;cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m,' '));   
    vector<pair<int,int>> pos;
    f(i,0,n){f(j,0,m){cin>>mat[i][j];}}


    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(mat[i][j] == '*')
                fall(i,j,n, mat);
        }
    }


    f(i,0,n){
        f(j,0,m){
            cout << mat[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";

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
