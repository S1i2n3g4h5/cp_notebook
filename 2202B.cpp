/*
Competing against Myself  
[zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
   (std::cout << ... << args) << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<ln
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
    
    one clear observation that during the construction process, for odd length the start=end char same   but for the even ones its different

    */

    ll n;cin>>n;
    string s;cin>>s;



    ll L=0, R=0;
    int p = 0; 


    auto adjust = [&](ll &l, ll &r, int parity){
        // print("..adjusting");
        if(p == 0){
            return parity == 0;
        } 
        else if(p == 1){
            return parity == 1;
        }
        else{
            
            if(l % 2 != parity) 
                l++;
            
            if(r % 2 != parity) {
                r--;

            }
            
            // print(l,",",r);
            return l <= r;
        }
    };



    f(j,1,n+1){
        int P = n-j+1; 
        char sj = s[j-1];


        // print(sj, " ", P, "   ", j);

        if(P % 2 != 0){
            // odd len = same ending    'a.....a'
            if(sj == 'a'){
                if(!adjust(L, R, 0)){ 
                    print("NO"); 

                    return; 
                }
                
                R++; 
                p = 2;
            } 
            else if(sj == 'b'){
                if(!adjust(L, R, 1)){ 
                    print("NO"); 
                    return; 
                }

                R++; 
                
                p = 2;
            } 
            else{
                R++; 
                p = 2;
            }
        } 
        else{  
            // evne

            if(sj == 'a'){
                L = L +(L % 2 == 0);
                R = R +(R % 2 == 0);

                p = 1;
            } 
            else if(sj == 'b'){
                L = L +(L % 2 != 0);
                R = R +(R % 2 != 0);
                
                p = 0;

            } 
            else{
                R++; 
                p = 2;
            }
        }


        
        
        if(L>R){
            print("NO");
            return;
        }
        
    }


    print("YES");


}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if(multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
