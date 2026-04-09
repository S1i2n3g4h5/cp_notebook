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
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];


    vector<ll>evenList,oddList;
    for(ll v : arr){
        if(v % 2 == 0) evenList.push_back(v);
        else oddList.push_back(v);
    }

    sort(evenList.begin(), evenList.end());reverse(evenList.begin(), evenList.end()); //desc
    sort(oddList.begin(), oddList.end());reverse(oddList.begin(), oddList.end());

    vector<ll> answer(n+1,0);
    int E=evenList.size();
    int O=oddList.size();

    
    vector<ll>prefE(E+1,0);
    f(i,1,E+1){
        prefE[i]=prefE[i-1]+ evenList[i-1];
    }


    if(O == 0){
        // no odd found so answer becomes 0 for all?
        f(k,1,n+1){
            cout<< 0<<(k == n ?'\n':' ');
        
        }
        return true;
    }

    ll mxOdd = oddList[0]; 


    f(k,1,n+1){
        int needFromOdd=0;

        int L = (k-1) -E;
        if(L < 0)
            L=0;

        if(L % 2 == 1) 
            needFromOdd = L+1;
        else 
            needFromOdd=L;
        // print(L, " ,", needFromOdd)
    
        if(needFromOdd > (O-1)){
            answer[k] = 0;
            continue;
        }

        int canTakeE = (k - 1) - needFromOdd;
        if(canTakeE < 0) {
            // print("k:", k, " canTakeE:", canTakeE);
            answer[k]=0;

            continue;
        }

        if(canTakeE >E) 
            canTakeE=E;

        answer[k]= mxOdd + prefE[canTakeE];
    }



    for(int k = 1; k <= n; k++){
        cout << answer[k] << (k == n ? '\n' : ' ');
    }
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