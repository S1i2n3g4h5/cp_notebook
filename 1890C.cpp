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
const bool multipleTestCases = 1;

void solve(){
  /*
    constraint -> inserting "01" at any pos  - >  atmost 300 ops

        1-based indexing output

    * since the problem statements asks to pair every index i with j
        so odd sized string not possible
    * similarly for even sized string its only possible if count of 0 n 1s are equal
      else disbalance can never be fixed.


    previously gone with string pure implementation but found that theres a STL for this
    <DEQUE>    
  */

  int n;cin>>n;
  string s;cin>>s;


  int o=0,z=0;
  f(i,0,n){
    if(s[i] == '0')z++;
    else o++;
  }


  // main condition
  if((n%2 == 0 and z!=o) or (n%2 == 1)){
    print(-1);
    return;
  }


  auto is_good = [&](string str){
    int i=0;
    int j=str.size()-1;
    while(i<j){
        if(str[i] == str[j] ){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
  };
    
    
  if(is_good(s)){
    print("0\n");
    return;
    }

    
    // deque option
    int i=0;
    vector<int>pos;
    deque<char> str(s.begin(), s.end());
    while(!str.empty()){
        if (pos.size() > 300){
            print("-1");
            return;
        }

        if(str.front() != str.back()){
            str.pop_front();
            str.pop_back();
            i++;
        }
        else{
            char curr_char = str.front();

            if(curr_char == '1'){
                // front push
                pos.push_back(i);
                
                str.push_front('1');
                str.push_front('0');
                
                
                i++;
            }
            else{
                // back push
                pos.push_back(i + str.size());

                str.push_back('0');
                str.push_back('1');
                
                i++;
            }
            
            str.pop_front();
            str.pop_back();
        }

    }

    print(pos.size());
    f(i,0,pos.size()){
        cout << pos[i] << " ";
    }
    cout << "\n";
    
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
