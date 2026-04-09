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


void solve(){
    
    int n,m,k;cin>>n>>m>>k;
    vector<int>room(n),customer(m);
    f(i,0,n)cin>>room[i];
    f(i,0,m)cin>>customer[i];
    
    sort(room.begin(), room.end());
    sort(customer.begin(), customer.end());

    int ri=0,ci=0;
    int cnt=0;

    while(ri < n and ci<m){
        if((room[ri]-k) <= customer[ci] and customer[ci]<=(room[ri]+k)){
            cnt++;
            ri++;
            ci++;
        }
        else if(room[ri] > customer[ci]) ci++;
        else ri++;
    }

    print(cnt);

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