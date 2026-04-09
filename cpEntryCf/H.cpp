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

    int n;cin>>n;
    vector<int> a(n),b(n);
    f(i,0,n)cin>>a[i];
    f(i,0,n)cin>> b[i];

    int max_a = a[n-1];
    int max_b = b[n-1];

    f(i,0,n-1){
        // print("-------------------");
        // print("a-", a[i]);
        // print("b-", b[i]);
        

        // print(max_a, max_b);

        if((a[i]>=max_a)  or  b[i]>=max_b){
            if((a[i]<=max_b)  and  b[i]<=max_a){
                // print("swpaing.");

                int tmp=a[i];
                a[i]=b[i];
                b[i]=tmp;


            }
        }

        if(a[i]>max_a  or  (b[i]>max_b)){
            print("No");
    
            return 1;    
        }
    }


    print("Yes");  

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