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



const bool multipleTestCases = 1;


bool check_beautiful(int a,int b,int c,int d){
    if(a<=b and c<=d and a<=c and b<=d)
        return true;
    return false;
}

vector<int> rotate(int a,int b, 
                   int c, int d){
    return {c,a,d,b};
}

void solve(){

    int a,b,c,d;cin>>a>>b;
    cin>>c>>d;

    if(check_beautiful(a,b,c,d)){
        print("YES");
        return;
    }
    
    f(i,0,4){
        vector<int> arr=rotate(a,b,c,d);
        a=arr[0];
        b=arr[1];
        c=arr[2];
        d=arr[3];
    
        if(check_beautiful(a,b,c,d)){
            print("YES");
            return;
        }

    }

  
    print("NO");

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


