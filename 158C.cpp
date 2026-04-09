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

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long



const bool multipleTestCases = 0; 


void solve(){
  /*
    
  */
 ll n; cin >> n;
vector<string> current_path;

    f(i, 0, n){
        string type;cin>>type; 
        
        
        if(type == "pwd"){
            cout << "/";
            f(j,0,current_path.size()){
                cout<< current_path[j] << "/";
            }
            cout << "\n";
        } 
        else{
            string arg;cin>>arg;
            
            if(arg[0]=='/'){
                current_path.clear();
            }


            f(j, 0, arg.size()){
                if(arg[j] == '/') arg[j] = ' ';
            }

            arg += " "; // safety space for the last token
            string temp = "";
            
            f(j,0,arg.size()){
                if(arg[j] != ' '){
                    temp += arg[j];
                } 
                else{
                
                    if(temp != ""){
                
                        if(temp == ".."){
                            if(!current_path.empty()){
                                current_path.pop_back();
                            }
                        } else{
                            current_path.push_back(temp);
                        }
                    }
                    temp = ""; 
                }
            }
        }
    }

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