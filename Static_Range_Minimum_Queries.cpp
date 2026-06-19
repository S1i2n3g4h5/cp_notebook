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



struct SegTree {
    int n;
    vector<long long> tree;

    // customize the default value
    const long long NEUTRAL = 1e18;

    // customize
    long long merge(long long left_child, long long right_child) {
        return min(left_child, right_child); // Change to min(), max(), gcd(), etc.
    }

    SegTree(int n) {
        this->n = n;
        tree.assign(4 * n, NEUTRAL);
    }

    void build(const vector<long long>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(a, 2 * node, start, mid);
        build(a, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void updateInternal(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            // customize: set to '=' for override, '+=' for addition
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateInternal(2 * node, start, mid, idx, val);
        } else {
            updateInternal(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    long long queryInternal(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return NEUTRAL;
        if (l <= start && end <= r) return tree[node];

        int mid = start + (end - start) / 2;
        return merge(queryInternal(2 * node, start, mid, l, r), 
                     queryInternal(2 * node + 1, mid + 1, end, l, r));
    }

    void update(int idx, long long val) { updateInternal(1, 0, n - 1, idx, val); }
    long long query(int l, int r) { return queryInternal(1, 0, n - 1, l, r); }
    void build(const vector<long long>& a) { build(a, 1, 0, n - 1); }
};


void solve(){
  /*
  
  */

  ll n,q;cin>>n>>q;
  vll a(n);
  f(i,0,n)cin>>a[i];


  SegTree segtree(n);

  segtree.build(a);

  while(q--){
    ll l,r;cin>>l>>r;

    cout << segtree.query(l-1,r-1) << "\n";
    
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
