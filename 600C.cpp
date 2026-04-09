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

    for palindromes conditions -
        if even length then even freq of chars available
        if odd length then only 1 character with odd len possible, other all evne frequency;
    mainly focusing onto the odd conversion as even is already setted

    and even for the odd to even conversion we try not to add new character but rather convert the existing odd ones into even (2pointer kind of)
  */

    string s;cin>>s;
    
    int n=s.size();

    map<int,int>freq;
    f(i,0,n){
        freq[s[i]]++;
    }

    vector<char>odd_cnt;
    for(auto p:freq){
        if(p.second & 1){
            odd_cnt.push_back(p.first);
        }
    }
    
    
    // pairing smallest odd freq from largest odd freq char
    int l=0, r=odd_cnt.size()-1;
    while(l<r){
        freq[odd_cnt[l]]++;
        freq[odd_cnt[r]]--;
        
        l++;r--;
    }

    
    string palindrome="";
    string middle="";

    for(auto p:freq){
        char c = p.first;
        int f = p.second/2;

        palindrome += string(f, c);

        if(p.second & 1){
            middle = c;
        }
    }   
    
    string rev = palindrome;
    sort(rall(rev));

    print(palindrome + middle + rev);

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