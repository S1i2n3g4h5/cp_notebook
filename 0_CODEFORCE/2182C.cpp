#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args) {
    (cout << ... << args) << "\n";
}

#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long



const bool multipleTestCases = 1;

void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n),c(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>>b[i];
    f(i,0,n)cin>>c[i];


    
    vector<char> head_torso(n,'Y');
    f(i,0,n){
        f(t,0,n){

            if(a[t] >=  b[ (t+i)%n ]){
                // print("not avble  -", a[t]);
                head_torso[i] = 'N';
                break;
                
            }
        }
    }


    vector<char>torso_leg(n,'Y');
    f(y,0,n){
        f(t,0,n){
            // print(b[t], " ", c[(t+y)%n]);
            if(b[t] >= c[(t+y)%n]){
                // print("not avble  -", b[t]);
                torso_leg[y] = 'N';
                break;

            }
        }
    }


    ll ok1=0,ok2=0;
    f(i,0,n){
        if(head_torso[i] == 'Y')
            ok1++;
        
        if(torso_leg[i]=='Y')
            ok2++;
    
        }

    print(ok1*ok2*n);

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