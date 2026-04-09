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


void solve(){

    int n,q;cin>>n>>q;
    vector<int> arr(n);
    f(i,0,n)cin>>arr[i];


    int ones=0,twos=0;
    int totalsum=0;
    f(i,0,n){
        totalsum+=arr[i];
        arr[i]==1?ones++:twos++;
    }
    

    f(_,0,q){
        int qt;cin>>qt;

        if(qt == 1){
            int sumreq;cin>>sumreq;

            if(sumreq > totalsum){
                print("NO");
                continue;
            }         
            else if (sumreq == totalsum){
                print("YES");
                continue;
            }                


            int need = totalsum - sumreq;
            
            
            if (need == 1){
                if (arr[0]==1  or arr[n-1]==1)
                    print("YES");
                else
                    print("NO");
            }
            else{
                if(need%2 == 0)
                    print("YES");
                else {
                    if(arr[0] ==1  or arr[n-1]==1)
                        print("YES");
                    else
                        print("NO");
                }
            }
            continue;
               

        }
        else{
            int newidx,newval;cin>>newidx>>newval;
            newidx--;
            
            // remove old value
            totalsum -= arr[newidx];
            if(arr[newidx] == 1){
                ones--;
            }
            else{
                twos--;
            }
            
            // add new value
            arr[newidx] = newval;
            if(newval == 1){
                ones++;
            }
            else{
                twos++;
                
            }

            totalsum+=newval;
        }
    }
    
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


