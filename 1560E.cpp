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

void solve(){
  /*
    restoration of initial string t;
    output -1  or <initial string, order of char to be removed>

    obs 1 -> last char of s = last char to be deleted
        and hence continue left from last char and the cahrs comming are the ones we need 2nd answer


    another great observaiton here with hard dry run is ->
        lets say 
        s = abacabaaacaac
        order- > b(1st) a(2nd) c(3rd)
        
        total cnt = a:8   b:2   c:3

        now original count in s-
            b: 2/1 = 2
            a: 8/2 = 4
            c: 3/3 = 1
            
            tot len of s: 2+4+1=7


    and for rebuilding we just using this order charaacters
    and the inital string length, to calc and build the answer esily :)

  */

    string s;cin>>s;


    // find the order in whcih deleted
    string order="";
    vector<bool>seen(26,false);
    for(int i=s.size()-1;i>=0;i--){
        if(!seen[s[i] - 'a']){
            seen[s[i] - 'a'] = 1;
            order += s[i];
        }
    }
    reverse(all(order));


    map<char,int>totcnt;
    f(i,0,s.size()){
        totcnt[s[i]]++;
    }
    

    int init_len =0;
    f(i,0,order.size()){        
        int pos = i+1;

        if(totcnt[order[i]] % (i+1) != 0){
            print(-1);
            return;
        }

        init_len += totcnt[order[i]] / (i+1);
    }

    // print(init_len);
    

    // construction
    string check="";
    string tempinit = s.substr(0,init_len);
    vector<bool>removed(26,false);

    for(auto c:order){

        check += tempinit;
        string next_init = "";

        removed[c - 'a'] = true;

        for(char x:tempinit){
            if(!removed[x-'a'])
                next_init += x;
        }

        tempinit = next_init;
    }



    if(check == s){
        print(s.substr(0,init_len), order );
    }
    else
        print(-1);

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