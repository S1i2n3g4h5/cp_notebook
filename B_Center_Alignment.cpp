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
 
    vector<string>arr;
    string curr_line;
    while(getline(cin, curr_line)){
        if(!curr_line.empty() and curr_line.back() == '\r'){
            curr_line.pop_back();
        }

        arr.push_back(curr_line);
    }
  
    ll n = arr.size();
    int mx_size = 0;
    f(i,0,n){
        mx_size = max(mx_size, (int)arr[i].size());
    }



    cout << string(mx_size+2, '*') << "\n";
    
    bool left_gets_fewer = true;
    f(i,0,n){
        int diff = mx_size - arr[i].length();
        int left_spaces = 0;
        int right_spaces = 0;

        if (diff % 2 == 0) {

            left_spaces = diff / 2;
            right_spaces = diff / 2;
        } 
        else {

            if (left_gets_fewer) {
                left_spaces = diff / 2;
                right_spaces = diff - left_spaces; 
            } 
            else {
                right_spaces = diff / 2;
                left_spaces = diff - right_spaces;
            }

            left_gets_fewer = !left_gets_fewer;
        }

        cout << "*" << string(left_spaces, ' ') << arr[i] << string(right_spaces, ' ') << "*\n";
    }
    
    cout << string(mx_size+2, '*') << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}