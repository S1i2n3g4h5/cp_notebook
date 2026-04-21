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


const bool multipleTestCases = 0; 

void solve(){
  /*
    ive found a good observation like which pari belongs whome -
    like ill do a loop in which using +1 val when fuond ( and -1 when )    so when i find the ( i put into this index in `last` list then if i find the ) i take last.back  and pair with it curernt index and store into maybe map  or vetor and continue and then remove the last.back();
    for nested strucutre ill be doing this -> like whe i found the +val >=2 then ill be putting the next vals pairs int another list until the val!=0 and the uput htis neested list as isnlge elemnt into my main pairing list 

    like this i cna easily define the strucutre for the list parts 


    ----

    tle due too looping fro setting ALIVE to false
    instead using juping logic direcrly


  */

    ll n,m,p;cin>>n>>m>>p;
    string s;cin>>s;
    string ops;cin>>ops;

    s = " " + s;

    vll match(n+1);
    vector<bool> alive(n+1, true);
    stack<ll>st;
    f(i,1,n+1){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            int j = st.top(); st.pop();
            match[i] = j;
            match[j] = i;
        }
    }


    auto moveLeft = [&](ll x){
        while(x>=1 and !alive[x]) x--;
        return x;
    };
    auto moveRight = [&](ll x){
        while(x<=n and !alive[x]) x++;
        return x;
    };


    vll next(n+2);
    f(i,1,n+2){
        next[i] = i;
    }

    function<ll(ll)> find_nxt = [&](ll x){
        if(x > n) return n+1;
        if(next[x] == x) return x;
        return next[x] = find_nxt(next[x]);
    };


    for(char c:ops){

        if(c == 'L'){
            p = moveLeft(p-1);
        }
        else if(c == 'R'){
            p = moveRight(p+1);
        }
        else{
            ll l = min(p, match[p]);
            ll r = max(p, match[p]);
           
            
            // f(i,l,r+1){
            //     alive[i] = false;
            // }
            ll i=find_nxt(l);
            while(i<=r and i<=n){
                alive[i] = false;
                next[i] = i+1;
                i = find_nxt(i);
            }


            ll nxt = moveRight(r+1);
            if(nxt <= n)
            p = nxt;
            else{
                p = moveLeft(l-1);
            }

        }

    }

    f(i,1,n+1){
        if(alive[i])
            cout << s[i];
    }
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