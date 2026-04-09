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



const bool multipleTestCases = 0;

bool good_taxi(string&s){
    return s[0]==s[1] and s[1]==s[3] and s[3]==s[4] and s[4]==s[6] and s[6]==s[7];
}

bool good_pizza(string&s){
    vector<int> d;
    for(char c : s){
        if(c != '-') d.push_back(c - '0');
    }
    for(int i=1;i<6;i++){
        if(d[i] >= d[i-1]) return false;
    }
    return true;
}


void solve(){
    int n;cin>>n;

    
    vector<string> names;       
    vector<vector<int>> cnt;    

    int mx_taxi=0,mx_pizza=0,mx_girl=0;

    f(i,0,n){
        int s;string name;
        cin>>s>>name;

        string available_phones;
        int pizzas=0,girls=0,taxi=0;
        f(j,0,s){
            cin>>available_phones;

            if(good_taxi(available_phones))taxi++;
            else if(good_pizza(available_phones))pizzas++;
            else girls++;
        }

        names.push_back(name);
        cnt.push_back({taxi,pizzas,girls});


        mx_taxi=max(taxi,mx_taxi);
        mx_pizza=max(pizzas,mx_pizza);
        mx_girl=max(girls,mx_girl);
    }

    // Taxi
    cout << "If you want to call a taxi, you should call: ";
    bool first = true;
    for(int i = 0; i < names.size(); i++){
        if(cnt[i][0] == mx_taxi){
            if(!first) cout << ", ";
            cout << names[i];
            first = false;
        }
    }
    cout << ".\n";


    // Pizza
    cout << "If you want to order a pizza, you should call: ";
    first = true;
    for(int i = 0; i < names.size(); i++){
        if(cnt[i][1] == mx_pizza){
            if(!first) cout << ", ";    
            cout << names[i];
            first = false;
        }
    }
    cout << ".\n";

    // Girls
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    first = true;
    for(int i = 0; i < names.size(); i++){
        if(cnt[i][2] == mx_girl){
            if(!first) cout << ", ";
            cout << names[i];
            first = false;
        }
    }
    cout << ".\n";

  
  return;
}


int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   