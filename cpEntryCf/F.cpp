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
const bool printYes = false;
const bool printNo = false;



bool solve(){

    int n; cin >> n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];

    vector<int> prefix_mod(n+1,0);
    f(i,1,n+1){
        prefix_mod[i] = (prefix_mod[i-1] + a[i-1])%3;

    }
    

    f(l,1,n-1){
        f(r,l+1,n){
            
            int s1 =prefix_mod[l];
            int s2 =(prefix_mod[r] - prefix_mod[l] + 3) % 3;

            int s3=(prefix_mod[n] - prefix_mod[r] + 3) % 3;

            // print(prefix_mod[n], "   , ", prefix_mod[r], " , ", prefix_mod[l]);
            // print(s1,", ", s2,", ",s3);

            if((s1==s2  and   s2==s3)  or (s1!=s2  and  s2!=s3  and s1!=s3)){
                print(l, " ", r);
                return 1;
            }
        }
    }

    print("0 0");



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