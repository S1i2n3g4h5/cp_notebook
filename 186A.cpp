/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 0;


void solve(){
  /*

  */
    string a,b;cin>>a>>b;

    if(a.size() != b.size()){
        print("NO");return;
    }


    vector<int>diffs;
    f(i,0,a.size()){
        if(a[i] != b[i])
            diffs.push_back(i);
    }

    if(diffs.size() == 2){

        int f1=diffs[0];
        int f2=diffs[1];

        if(a[f1]==b[f2] and b[f1] == a[f2]) print("YES");
        else{
            print("NO");
        }
    }
    else
        print("NO");
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
