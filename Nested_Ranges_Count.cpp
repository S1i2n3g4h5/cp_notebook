/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
    yeah iknow this quesiton required that pdbs data structure

  */


    int n;cin>>n;
    vector<vector<int>>range(n, vector<int>(3,0));
    f(i,0,n){
        cin>>range[i][0]>>range[i][1];
        range[i][2]=i;
    }

    sort(all(range), [&](auto a,auto b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    });


    ordered_multiset st;
    vector<int>ans1(n,0),ans2(n,0);


    f(i,0,n){
        int l=range[i][0];
        int r= range[i][1];
        int idx=range[i][2];

        // all vals having end oint greater than `this ending`  ->>   => totalsize - `this ending`
        int val = st.size() - st.order_of_key({r,-i}); 

        st.insert({r,-i});

        ans1[idx] = val;
    }


    st.clear();
    for(int i=n-1;i>=0;i--){
        int l=range[i][0];
        int r= range[i][1];
        int idx=range[i][2];
    
        st.insert({r,-i});
        int val = st.order_of_key({r,-i});
        
        ans2[idx] = val;
    }


    f(i,0,n)cout << ans2[i] << " ";
    cout <<"\n";
    f(i,0,n)cout << ans1[i] << " ";

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