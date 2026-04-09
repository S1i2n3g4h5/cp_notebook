#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}



// ______________________________________________________
const bool multipleTestCases = 0;

void solve(){

    int cust,m;cin>>cust>>m;
    
    priority_queue<int> max_heap; 
    priority_queue<int, vector<int>, greater<int>> min_heap; 
    f(i,0,m){
        int x;cin>>x;
        max_heap.push(x);
        min_heap.push(x);
    }

    

    int max_cost = 0;
    int temp_n = cust;
    while(temp_n--){
        int top = max_heap.top();
        max_heap.pop();
        max_cost += top;
        
        if(top - 1 > 0)
            max_heap.push(top - 1);
    }


    int min_cost = 0;
    temp_n = cust;
    while(temp_n--){
        int top = min_heap.top();
        min_heap.pop();
        min_cost += top;
        
        if(top - 1 > 0)
            min_heap.push(top - 1);
    }

    print(max_cost, " ", min_cost);

}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
