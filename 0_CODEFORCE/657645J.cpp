#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = true;

bool solve(){
    string s;cin>>s;
    string a;
    vector<int>lo,up; 
    a.reserve(s.size());
    lo.reserve(s.size()); 
    up.reserve(s.size());

    for(char c:s){
        // print(c);
        // cout << "\n ---------------- \n" << "-> "<<c << endl; 

        if(c=='b'){
            if(!lo.empty()){
                int idx=lo.back(); lo.pop_back();
                // cout << "\tLower rem  - " << idx << ", "<< a[idx];
                a[idx] = '#';    
            }
        }
        else if(c=='B'){
            
            if(!up.empty()){
                int idx=up.back(); 
                up.pop_back();
                
                // cout << "\tUpper rem  - " << idx << ", "<< a[idx];
                a[idx] = '#';
            
            }
        }
        else{
            if(islower(c)) lo.push_back(a.size());
            else up.push_back(a.size());
        
            a.push_back(c);
        }

    }


    for(char&c:a) if(c!='#') cout<<c;
    
    cout<<endl;

    return 1;
}

 
int main() {
  ios::sync_with_stdio(0);


  cin.tie(0);
  
  cout.tie(0);
  
    int t = 1;
    multipleTestCases and cin >> t;
    
    while(t--){
  
  
      solve();
  
    }
  
    return 0;
}   