/*
  Cmedpeting against Myself  
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
#define debug(x) cout<<#x<<" = "<<x<<ln
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



const int mx_limit = 1000005;
int mn[mx_limit],mx[mx_limit],med[mx_limit];

void solve(){
  /*
  
  */
  
  int n;cin>>n;
  vector<int> a(n);
  int v_cnt = 0;
  int v_idx = -1;
  long long total_moves = 0;

  f(i,0,n){
    cin>>a[i];
    
    if(i>=1  and a[i-1] > a[i]){
      v_cnt++;
      v_idx = i-1;
    }
    
    
    if(a[i] >=2){
      total_moves += (med[a[i]] - 1);
      
    }
      
  }

  
  if(v_cnt == 0){
    print("Bob");
    return;
  }

  
  if(v_cnt >= 2) {
    print("Alice");
    return;
  }

  
  if (total_moves%2 != 0){
    print("Alice");
    return;
  }

  
  int left_limit = (v_idx > 0  ? a[v_idx-1] : 1);
  int right_limit = a[v_idx+1];
  

  if(med[a[v_idx]] < 2  or mn[a[v_idx]] < left_limit  or mx[a[v_idx]] > right_limit) 
    print("Alice");
  else{
    print("Bob");
  }


}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  f(i,2,mx_limit){
      if(!mn[i]){
          for(int j = i; j < mx_limit; j += i){
              if(!mn[j]) mn[j] = i;
              mx[j] = i;
          }
      }
      med[i] = med[i / mn[i]] + 1;
  }
  
  
  int t;
  cin >> t;
  while(t--){
      solve();
  }
}