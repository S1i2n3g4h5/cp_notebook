/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
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


void dfs(int r, int c,int n, int m, vector<vector<char>>&arr, vector<vector<bool>>&visit){
    if(r<1 or r>n or c<1 or c>m or visit[r][c] or arr[r][c] == '#'){
        return;
    }

    visit[r][c] = true;
    dfs(r+1,c,n,m,arr,visit);
    dfs(r-1,c,n,m,arr,visit);
    dfs(r,c+1,n,m,arr,visit);
    dfs(r,c-1,n,m,arr,visit);

}

void solve(){
  /*
    running a dfs from n,m exit to start is better and easy

    cuz then we can easily check - 
        if(grid==G and visit[i][j]==false)
        and if(grid==B and visit[i][j] ==true);

    we can also greedily choose to enclose the B cells by surrounding them with the walls
    and then chekcing if the path is optimall built or not

  */

    int n,m;cin>>n>>m;
    vector<vector<char>>arr(n+1,vector<char>(m+1,' '));
    f(i,1,n+1){
        f(j,1,m+1){
            cin>>arr[i][j];
        }
    }

    vector<vector<bool>>visit(n+1,vector<bool>(m+1,false));
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    f(i,1,n+1){
        f(j,1,m+1){
            if(arr[i][j] == 'B'){

                for(int k=0;k<4;k++){
                    int ni = i + dr[k];
                    int nj = j+dc[k];

                    if(ni>=1 and ni<=n and nj>=1 and nj<=m){
                        // already someone there
                        if(arr[ni][nj] == 'G'){
                            print("No");
                            return;

                        }

                        if(arr[ni][nj] == '.')
                            arr[ni][nj] = '#';

                    }

                }

            }
        }
    }


    dfs(n,m,n,m,arr,visit);


    f(i,1,n+1){
        f(j,1,m+1){
            if((arr[i][j] == 'B' and visit[i][j]) or (arr[i][j] == 'G' and !visit[i][j])){
                print("No");
                return;
            }
        }
    }


    print("Yes");

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