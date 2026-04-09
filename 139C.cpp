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


string find_rhyme(vector<string> lines){
    // aaaa
    if(lines[0] == lines[1] and lines[1] == lines[2] and lines[2] == lines[3]){
        return "aaaa";
    }
    
    // aabb
    if(lines[0] == lines[1] and lines[2]==lines[3]){
        return "aabb";
    }

    //abab
    if(lines[0] == lines[2] and lines[1]==lines[3]){
        return "abab";
    }

    //abba
    if(lines[0]==lines[3] and lines[1]==lines[2]){
        return "abba";
    }

    return "NO";
}


void solve(){
  /*
    1 quatrains - 4lines

    During input, needs some pre-checks like if the given quatraine have atleast k vowels;


    <<Main keytakeway after 5 WAs- >

        during reading the problem statement i deduced that 
        if 1 rhymn gives `NO` then its never gonna make 
        any common rhymn sequence with other quatrains.

        But didnt implemented it while writing.


        So always remember to write down insights on the go as finding.
    */
    string vowels = "aeiou";

    int n,k;cin>>n>>k;
    // vector<vector<string>>arr;
    vector<string>rhyming;
    int universal_aaaa_cnt=0;
    f(i,0,n){

        vector<string> quatrains;
        bool have_k_vowels = true;


        f(j,0,4){
            string line;cin>>line;
            int ln_sz = line.size();

            // Here pre-processing done.
            // like if char less than k
            int vowel_cnt=0;
            int vowel_idx=ln_sz-1;
            for(int i=ln_sz-1;i>=0;i--){
                if(vowels.find(line[i]) != string::npos){
                    vowel_cnt++;
                    vowel_idx=i;
                }

                // break cuz kth suffix vowel reached...
                if(vowel_cnt >= k){
                    break;
                }
            }


            // __RHYMING NOT POSSIBLE
            if(vowel_cnt < k){  
                have_k_vowels = false;
                break;
            }

            // print(line.substr(vowel_idx));

            if(vowel_idx == 0){
                quatrains.push_back(line);
            }
            else{   
                quatrains.push_back(line.substr(vowel_idx));
            }

        }

        
        // Only append if this given line has possible rhyming schemes
        if(have_k_vowels){
            string rhyme_scheme = find_rhyme(quatrains);
            
            if(rhyme_scheme != "NO"){
                rhyming.push_back(rhyme_scheme);
                // arr.push_back(quatrains);
            }
            else{
                print("NO");
                return;
            }
        }
        else{
            print("NO");
            return;
        }

    }    


    // Finding common rhyming scheme

    int aaaa_cnt=0;
    string common_seq="";

    f(i,0,rhyming.size()){
        if(rhyming[i] == "aaaa")
            aaaa_cnt++;
        else{
            if(common_seq.empty()){
                common_seq = rhyming[i];
            }

            // Checking..
            if(common_seq != rhyming[i]){
                print("NO");
                return;
            }
        }
    }

    
    if(common_seq.empty()){
        if(aaaa_cnt>=1){
            print("aaaa");
        }
        else{
            print("NO");
        }
    }else{
        print(common_seq);
    }


}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
